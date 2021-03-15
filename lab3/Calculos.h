#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Calculos{
    private:
    int N;
    double xk, r, r2, b0, b1, yk;
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
    int validaciones(vector<double>, vector<double>);

};


    //.i
    Calculos::Calculos(){
        N = 0;
        xk = r = r2 = b0 = b1 = yk = 0.0; 
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

        int resultadoValidaciones = 0;
        resultadoValidaciones = validaciones(x, y);
        if (resultadoValidaciones==1){ // validacion regresa 1 si hay un error, 0 si no lo hay
            return;
        }


        
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

    //.i
    void Calculos::imprimir(){
        cout << "N  = " << N << endl;
        cout << "xk = " << xk << endl;
        printf("r  = %.5f \n", r);
        printf("r2 = %.5f \n", r2);
        printf("b0 = %.5f \n", b0);
        printf("b1 = %.5f \n", b1);
        printf("yk = %.5f \n", yk);
    }

    //.i
    int Calculos::validaciones(vector<double> x, vector<double> y){
        if (x.size() != y.size() ){
            cout << "No se recibieron el mismo numero de pares de x, y" << endl;
            return 1;
        }
        if (x.size() == 0 && y.size() == 0){
            cout << "No hay datos" << endl;
            return 1;
        }
        if (x.size()< 0){
            cout << "Numero de datos de x incorrecto." << endl;
            return 1;
        }
        if (y.size() < 0){
            cout << "Numero de datos de y incorrecto." << endl;
            return 1;
        }

        if (xk < 0 ){
            cout << "Error en valor de xk. Es menor a 0" << endl;
            return 1;
        }

        bool error = false;

        for (int i=0; i<x.size(); i++){
            if (x[i]<0){
                cout << "Error en x[" << i << "] = " << x[i] << " --- Valor menor a 0" << endl;
                error = true;
            }
            if (y[i]<0){
                cout << "Error en y[" << i << "] = " << y[i] << " --- Valor menor a 0" << endl;
                error = true;
            }
        }
        if (error){
            cout << "Terminando programa." << endl;
            return 1;
        }
        return 0;
    }