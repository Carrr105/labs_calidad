//.b=135
#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
#include "GJordan.h"
using namespace std;

class Calculos{
    private:
    int N;
    double wk, xk, yk, zk, r, r2, b0, b1, b2, b3, sig, ran; //.m
    double sumXY, sumW, sumX, sumY, sumZ, avgX, avgY, sumX2, sumY2, sumW2;
    
    public:
    Calculos();
    void calculaYMuestra(double, double, double, vector<double>, vector<double>, vector<double>, vector<double>); //.m
    double getSumXY(vector<double>, vector<double>);
    double getSumV(vector<double>);
    double getSumSquared(vector<double>);
    //.d=4
    void imprimir();
    //.d=2
};


    //.i
    Calculos::Calculos(){
        N = 0;
        wk = xk = r = r2 = b0 = b1 = b2 = b3 = yk = sig = ran = 0.0; 
        sumXY=0;
        sumX = 0;
        sumY = 0;
        sumW = 0;
        sumZ = 0;
        avgX = 0;
        avgY = 0;
        sumX2 = 0;
        sumY2 = 0;
    }

    //.i
    void Calculos::calculaYMuestra(double wkRecibido, double xkRecibido, double ykRecibido,
                                     vector<double> w, vector<double> x, vector<double> y, vector<double> z){ //.m
        xk = xkRecibido;
        wk = wkRecibido;
        yk = ykRecibido;
        GJordan gj;

        N = x.size();
        //.d=1
        sumW = getSumV(w);
        sumZ = getSumV(z);
        sumX = getSumV(x);
        sumY = getSumV(y);
        //.d=9
        double matrix[4][5];
        matrix[0][0] = N;
        matrix[0][1] = sumW;
        matrix[0][2] = sumX;
        matrix[0][3] = sumY;
        matrix[0][4] = sumZ;

        matrix[1][0] = sumW;
        matrix[1][1] = getSumSquared(w);
        matrix[1][2] = getSumXY(w, x);
        matrix[1][3] = getSumXY(w, y);
        matrix[1][4] = getSumXY(w, z);

        matrix[2][0] = sumX;
        matrix[2][1] = getSumXY(x, w);
        matrix[2][2] = getSumSquared(x);
        matrix[2][3] = getSumXY(x, y);
        matrix[2][4] = getSumXY(x, z);

        matrix[3][0] = sumY;
        matrix[3][1] = getSumXY(y, w);
        matrix[3][2] = getSumXY(y, x);
        matrix[3][3] = getSumSquared(y);
        matrix[3][4] = getSumXY(y, z);

        gj.gaussJordan(matrix);

        b0 = gj.getb0();
        b1 = gj.getb1();
        b2 = gj.getb2();
        b3 = gj.getb3();

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

    //.d=5

    //.i
    void Calculos::imprimir(){
        cout << "N  = " << N << endl;
        printf("wk = %.5f \n", wk);
        printf("xk = %.5f \n", xk);
        printf("yk = %.5f \n", yk);
        cout << "------------" << endl;
        printf("b0 = %.5f \n", b0);
        printf("b1 = %.5f \n", b1);
        printf("b2 = %.5f \n", b2);
        printf("b3 = %.5f \n", b3);
        cout << "------------" << endl;
        printf("zk = %.5f \n", b0 + b1 * wk + b2 * xk + b3 * yk);
        //.d=7
    }

    //.d=45