//.b=37
// Carlos Gerardo Herrera Cortina  A00821946
// Programa 4.
//.d=4
// incluyo clases
//.d=1
#include "Simpson.h" //.m
//.d=2

int main(){
    //.d=2
    double x=0.0; //.m
    double dof=0.0;

    cout << "Introduce x: "; //.m
    cin >> x; //.m
    if (!cin){
        cout << "Entrada inválida. Terminando programa." << endl;
        return 1;
    }
    if (x < 0 ){
        cout << "Error en dato, número incorrecto recibido. Terminando programa." << endl;
        return 1;
    }
    cout << "Introduce dof: "; //.m
    cin >> dof; //.m
    if (!cin){
        cout << "Entrada inválida. Terminando programa." << endl;
        return 1;
    }
    //.d=17
    if (dof > 0 && floor(dof)==dof){
        Simpson simpson(x, dof); //.m
        simpson.calcSimpson();
    }
    else{
        cout << "Error en dato, número incorrecto recibido. Terminando programa." << endl;
        return 1;
    }
    //.d=7
    return 0; 
}