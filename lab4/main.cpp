//.b=37
// Carlos Gerardo Herrera Cortina  A00821946
// Programa 4.
#include <iostream>
//.d=2
#include <unistd.h> // validacion de existencia de archivo
// incluyo clases
//.d=1
#include "Simpson.h" //.m
//.d=1

using namespace std;



int main(){
    //.d=2
    double x=0.0; //.m
    double dof=0.0;

    cout << "Introduce x: "; //.m
    cin >> x; //.m
    if (!cin){
        cout << "Caracter invalido. Terminando programa." << endl;
        return 1;
    }
    cout << "Introduce dof: "; //.m
    cin >> dof; //.m
    if (!cin){
        cout << "Caracter invalido. Terminando programa." << endl;
        return 1;
    }
    //.d=17
    if (x >= 0 && dof > 0 && floor(dof)==dof){
    Simpson simpson(x, dof); //.m
    simpson.calcSimpson();
    }
    else{
        cout << "Error en datos, numero incorrecto recibido. Terminando programa." << endl;
    }
    //.d=7

    return 0; 
}