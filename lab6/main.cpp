//.b=
// Carlos Gerardo Herrera Cortina  A00821946
// Programa 6.
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h> // validacion de existencia de archivo
// incluyo clases
#include <fstream> // manejo de archivos
#include "Calculos.h"
#include "Lectura.h"
using namespace std;

int main(){
    vector<double> x, y;
    double xk;
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
       && name.substr(name.find_last_of(".") + 1) != "rtf" && name.substr(name.find_last_of(".") + 1) != "cpp"
       && name.substr(name.find_last_of(".") + 1) != "c" && name.substr(name.find_last_of(".") + 1) != "h"
       && name.substr(name.find_last_of(".") + 1) != "java"){
      cout << "El archivo no es compatible" << endl;
      return 1;
    }

    fclose(f);

    Lectura lect;
    Calculos calc;
    if (lect.lee(name) == 1){
      return 1;
    }
    x = lect.regresaX();
    y = lect.regresaY();
    xk = lect.regresaXK();
    calc.calculaYMuestra(xk, x, y);

    return 0; 
}