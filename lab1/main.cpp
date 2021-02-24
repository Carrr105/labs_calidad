// Carlos Gerardo Herrera Cortina  A00821946
// Programa 1.
#include <iostream>
#include <unistd.h> // validacion de existencia de archivo
// incluyo clases
#include <fstream> // manejo de archivos
#include "BlankCount.h"
#include "CommCount.h"
using namespace std;

int main(){
    string name;
    cout << "Introduce nombre de archivo: ";
    cin >> name;
    BlankCount bc(name);
    CommCount cc(name);
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
        return 1;
    }
    
    if(name.substr(name.find_last_of(".") + 1) != "txt"){
      cout << "El archivo no es .txt" << endl;
      return 1;
    }

    fclose(f);


    int empty=0, code=0, comm=0, total=0;
    empty = bc.CountEmptylines();
    comm = cc.CountCommlines();
    total = cc.getTotal();
    code = total-comm-empty;
    cout << "Nombre del archivo: " << name << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Cantidad de líneas en blanco: " << empty << endl;
    cout << "Cantidad de líneas con comentarios: " <<  comm << endl;
    cout << "Cantidad de líneas con código: " << code << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Cantidad total de líneas: " <<  total << endl;
    return 0;
}