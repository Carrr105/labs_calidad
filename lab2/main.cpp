// Carlos Gerardo Herrera Cortina  A00821946
// Programa 2.
#include <iostream>
#include <unistd.h> // validacion de existencia de archivo
// incluyo clases
#include <fstream> // manejo de archivos
#include "BlankCount.h"
#include "CommCount.h"
#include "NewBlank.h"
using namespace std;

int main(){
    int numArch=0;
    cout << "Introduce numero de archivos para leer: ";
    cin >> numArch;
    if (numArch<=0){
      cout << "Nada que leer" << endl;
      return 1;
    }
    string name;
    cout << "Introduce nombre de archivos: " << endl;

    cin >> name;
    NewBlank bc(name);
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
    //cout << name << endl;
    if(name.substr(name.find_last_of(".") + 1) != "txt"  && name.substr(name.find_last_of(".") + 1) != "src"
    && name.substr(name.find_last_of(".") + 1) != "cpp" && name.substr(name.find_last_of(".") + 1) != "c"){
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
    cout << "T: " << code << endl;
    cout << "I: " << cc.getiCount() << endl;
    cout << "B: " << cc.getbCount() << endl;
    cout << "D: " << cc.getdCount() << endl;
    cout << "M: " << cc.getmCount() << endl;
    cout << "A: " << cc.getaCount(code) << endl;

    //si m = 0, es reusada
    // si b= 0, es nueva
    cout << "------------------------------------------------" << endl;
    cout << "Cantidad total de líneas: " <<  total << endl;
    return 0; 
}