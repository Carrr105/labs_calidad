#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Calculos{
    private:
    int N, xk;
    double r, r2, b0, b1, yk;
    double sumXY, sumX, sumY, avgX, avgY, sumX2, sumY2;
    
    public:
    Calculos(){
        xk = N = 0;
        r = r2 = b0 = b1 = yk = 0; 
        sumXY=0;
        sumX = 0;
        sumY = 0;
        avgX = 0;
        avgY = 0;
        sumX2 = 0;
        sumY2 = 0;
    }

    void calculaYMuestra(double xkRecibido, vector<double> x, vector<double> y){
        if (x.size() != y.size() ){
            cout << "No se recibieron el mismo numero de pares de x, y" << endl;
            return;
        }
        if (x.size() == 0 && y.size() == 0){
            cout << "No hay datos" << endl;
            return;
        }
        /*
        for (int i=0; i<x.size(); i++){
            cout << "x[" << i << "] = " << x[i] << endl;
        }

        for (int i=0; i<y.size(); i++){
            cout << "y[" << i << "] = " << y[i] << endl;
        }
        */

        xk = xkRecibido;
        int Naux = x.size();
        N = static_cast<double>(Naux);
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

        imprimir();

    }

    double getSumXY(vector<double> x, vector<double> y ){
        double suma=0;
        for (int i=0; i<x.size(); i++){
            suma+=x[i]*y[i];
        }
        return suma;
    }

    double getSumV(vector<double> v ){
        double suma=0;
        for (int i=0; i<v.size(); i++){
            suma+=v[i];
        }
        return suma;
    }

    double getSumSquared(vector<double> v ){
        double suma=0;
        for (int i=0; i<v.size(); i++){
            suma+=(v[i]*v[i]);
        }
        return suma;
    }

    double getB1(){
    /*    cout << "xd: " << sumXY-(N*avgX*avgY) << endl;
        cout << "under: " << (sumX2-(N*avgX2)) << endl;

        cout << "sumX2: " << sumX2 << endl;
        cout << "avgX2: " << avgX2 << endl; */
        
        return (sumXY-N*avgX*avgY) / (sumX2-N*avgX*avgX);
    }

    double getR(){
        double under = (N*sumX2-(sumX*sumX)) * (N*sumY2-(sumY*sumY));
   /*     cout << "sumXY: " << sumXY << endl;
        cout << "sumX2: " << sumX2 << endl;
        cout << "sumX: " << sumX << endl;
        cout << "sumY2: " << sumY << endl;
        cout << "sumY: " << sumY << endl;
        cout << "under: " << under << endl; 
        double raiz = sqrt(under);
        cout << "raiz: " << raiz << endl; */
        return (N*sumXY-sumX*sumY) /  sqrt( under  );
    }

    void imprimir(){
        cout << "N  = " << N << endl;
        cout << "xk = " << xk << endl;
        printf("r  = %.5f \n", r);
        printf("r2 = %.5f \n", r2);
        printf("b0 = %.5f \n", b0);
        printf("b1 = %.5f \n", b1);
        printf("yk = %.5f \n", yk);
    }




};