#include <iostream>
// incluyo clases
#include <fstream>
#include "BlankCount.h"
#include "CommCount.h"
using namespace std;

int main(){
    string name;
    cin >> name;
    BlankCount bc(name);
    CommCount cc(name);
    FILE *file;
    if (!(file = fopen("archivo1.txt", "r"))) {
        fclose(file);
        exit(1);
    }


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