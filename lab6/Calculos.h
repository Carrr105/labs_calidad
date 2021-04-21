//.b=106
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include "Simpson.h"
using namespace std;

class Calculos{
    private:
    int N;
    double xk, r, r2, b0, b1, yk, sig, ran;
    double sumXY, sumX, sumY, avgX, avgY, sumX2, sumY2;
    
    public:
    Calculos();
    void calculaYMuestra(double, vector<double>, vector<double>);
    double getSumXY(vector<double>, vector<double>);
    double getSumV(vector<double>);
    double getSumSquared(vector<double>);
    double getB1();
    double getR();
    void imprimir();
    //.d=1
    double getSignificance();
    double getX(double, double);
    double stdDev(vector<double>, vector<double>);
    double getSumSquared2N(vector<double>);
};


    //.i
    Calculos::Calculos(){
        N = 0;
        xk = r = r2 = b0 = b1 = yk = sig = ran = 0.0; 
        sumXY=0;
        sumX = 0;
        sumY = 0;
        avgX = 0;
        avgY = 0;
        sumX2 = 0;
        sumY2 = 0;
    }

    //.i
    void Calculos::calculaYMuestra(double xkRecibido, vector<double> x, vector<double> y){
        xk = xkRecibido;

        N = x.size();
        sumXY = getSumXY(x,y);
        sumX = getSumV(x);
        sumY = getSumV(y);
        sumX2 = getSumSquared(x);
        sumY2 = getSumSquared(y);
        avgX = sumX/x.size();
        avgY = sumY/y.size();

        b1 = getB1();
        b0 = avgY-(b1*avgX);
        r = getR();
        r2 = r*r;
        yk = b0+b1*xk;
        sig = getSignificance();
        ran = getX(0.35, N-2.0) * stdDev(x, y)*sqrt(1.0 + (1.0/N) + (pow(xk - avgX, 2)) / (getSumSquared2N(x))); 

        imprimir();

    }

    //.i
    double Calculos::getSumXY(vector<double> x, vector<double> y ){
        double suma=0;
        for (int i=0; i<x.size(); i++){
            suma+=x[i]*y[i];
        }
        return suma;
    }

    //.i
    double Calculos::getSumV(vector<double> v ){
        double suma=0;
        for (int i=0; i<v.size(); i++){
            suma+=v[i];
        }
        return suma;
    }

    //.i
    double Calculos::getSumSquared(vector<double> v ){
        double suma=0;
        for (int i=0; i<v.size(); i++){
            suma+=(v[i]*v[i]);
        }
        return suma;
    }

    //.i
    double Calculos::getB1(){  
        return (sumXY-N*avgX*avgY) / (sumX2-N*avgX*avgX);
    }

    //.i
    double Calculos::getR(){
        double under = (N*sumX2-(sumX*sumX)) * (N*sumY2-(sumY*sumY));
        return (N*sumXY-sumX*sumY) /  sqrt( under  );
    }

    //.d=28

    //.i
    void Calculos::imprimir(){
        cout << "N  = " << N << endl;
        printf("xk = %.5f \n", xk);
        printf("r  = %.5f \n", r);
        printf("r2 = %.5f \n", r2);
        printf("b0 = %.5f \n", b0);
        printf("b1 = %.5f \n", b1);
        printf("yk = %.5f \n", yk);
        printf("sig= %.10f \n", sig);
        printf("ran= %.5f \n", ran);
        printf("LS = %.5f \n", yk + ran);
        if (yk - ran < 0){
            printf("LI = %.5f \n", 0.00000);
        }
        else {
            printf("LI = %.5f \n", yk - ran);
        }
    }


    //.i
    double Calculos:: getSignificance(){
        double x =  ( r*sqrt(N-2) ) / sqrt(1-(r*r));
        Simpson simp (x, N-2);
        return 1-2*simp.calcSimpson();
    }

    //.i
    double Calculos :: getX(double pUser, double dofReceived){
        double x = 1.0;
        double p = 0.0;
        double d = 0.5;
        bool isLow = false;
        Simpson simpson(x, dofReceived);
        double pAux = simpson.calcSimpson();

        if (pAux > pUser){
            isLow = false;
            x-=d;
        }
        else{
            isLow = true;
            x+=d;
        }
        do{
            simpson.setXDOF(x, dofReceived);
            p = pAux;
            pAux = simpson.calcSimpson();
            if (pAux > pUser) {
				if (isLow) 
					d /= 2;
				isLow = false;
			}
            else if (pAux < pUser) {
			    if (!isLow)
                    d/=2;
				isLow = true;
			}

            if (pAux < pUser) {
				x += d;
			}
			else {
				x -= d;
			}
        } while (abs(p - pAux) > 0.00000001);
        return x;
    }

    //.i
    double Calculos:: stdDev(vector<double> x, vector<double> y){
        double stdDev = 0;
        for (int i = 0; i<N; i++){
            stdDev += pow(y[i]-b0-b1*x[i], 2);
        }
        stdDev *= (1 / ((N*1.0)-2)); // N se multiplica por 1.0 para hacerse double y que la operacion funcione
        stdDev = sqrt(stdDev);
        return stdDev;
        }

    //.i
    double Calculos:: getSumSquared2N(vector<double> x){
        double sum = 0;
        
        for (int i=0; i<N; i++){
            sum += pow(x[i]-avgX, 2);
        }

        return sum;
    }