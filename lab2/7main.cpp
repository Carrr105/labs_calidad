//.b=37
// Carlos Gerardo Herrera Cortina  A00821946
// Programa 7.
//.d=3
#include <unistd.h> // validacion de existencia de archivo
//.d=1
// incluyo clases
#include "Calculos.h"
#include "Lectura.h"
//.d=1

//.i
int main(){
    vector<double> w, x, y, z; //.m
    double wk, xk, yk;
    string name;
    cout << "Introduce nombre de archivo: ";
    cin >> name;

    const char * c = name.c_str();
    if (access( c, F_OK ) != 0){
      cout << "El archivo no existe" << endl;
      return 1;
    }

    char ch;
    FILE *f = fopen(c, "r");
    if(fscanf(f,"%c",&ch)==EOF)
    {
        cout << "El archivo está vacio" << endl;
        fclose(f);
        return 1;
    }

    if(name.substr(name.find_last_of(".") + 1) != "txt" && name.substr(name.find_last_of(".") + 1) != "src"
       && name.substr(name.find_last_of(".") + 1) != "rtf"){ //.m
       cout << "El archivo no es compatible" << endl;
       return 1;
    }

    fclose(f);

    Lectura lect;
    Calculos calc;
    if (lect.lee(name) == 1){
      return 1;
    }
    w = lect.regresaW();
    x = lect.regresaX();
    y = lect.regresaY();
    z = lect.regresaZ();
    wk = lect.regresaWK();
    xk = lect.regresaXK();
    yk = lect.regresaYK();
    calc.calculaYMuestra(wk, xk, yk, w, x, y, z); //.m

    return 0; 
}