//.b=41
// Carlos Gerardo Herrera Cortina  A00821946
// Programa 2.
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unistd.h> // validacion de existencia de archivo
// incluyo clases
#include <fstream> // manejo de archivos
#include "BlankCount.h"
#include "FileCount.h"
#include "CommCount.h"
#include "NewBlank.h"
using namespace std;


int main(){
    int totalLDC = 0;
    int numArch=0;
    cout << "Introduce numero de archivos para leer: ";
    cin >> numArch;
    if (!cin){
      cout << "Se requiere un numero de entrada." << endl;
      return 1;
    }
    if (numArch<=0){
      cout << "Nada que leer" << endl;
      return 1;
    }
    string name;
    cout << "Introduce nombre de archivos: " << endl;

    vector<string> nombres;
    vector<FileCount> files;
    int empty=0, code=0, comm=0, total=0;

    for (int i=0; i<numArch; i++){
      cin >> name;
      nombres.push_back(name);

    // validacion

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
    
    if(name.substr(name.find_last_of(".") + 1) != "txt" && name.substr(name.find_last_of(".") + 1) != "src"
       && name.substr(name.find_last_of(".") + 1) != "rtf" && name.substr(name.find_last_of(".") + 1) != "cpp"
       && name.substr(name.find_last_of(".") + 1) != "c" && name.substr(name.find_last_of(".") + 1) != "h"
       && name.substr(name.find_last_of(".") + 1) != "java"){ //.m
      cout << "El archivo no es compatible" << endl; //.m
      return 1;
    }

    fclose(f);




    }

    vector <string> nombresExt = nombres;


    for (int i=0; i<numArch; i++){
    size_t lastdot = nombres[i].find_last_of(".");
    if (lastdot == string::npos){ 
       // do nothing
    }
    else {
      nombres[i] = nombres[i].substr(0, lastdot);
    }
    }


    vector<string> unique1 = nombres;

    string nombreSal = "ConteoLDC.txt";
    const char * d = nombreSal.c_str();
    if (access( d, F_OK ) != 0){
      cout << "No se pudo crear archivo de salida. Continuando ejecución en consola..." << endl;
      return 1;
    }

    ofstream archSalida;
    archSalida.open("ConteoLDC.txt");

    unique1.erase(unique(unique1.begin(), unique1.end()), unique1.end());

    int iGlobal, mGlobal, tGlobal, dGlobal, bGlobal;
    int iN=0;
  iGlobal=mGlobal = tGlobal = dGlobal = bGlobal = 0;
  bool found = false;

    cout << "CLASES BASE: " << endl;
    archSalida << "CLASES BASE: " << endl;



    for (int i=0; i<unique1.size(); i++){
      for (int j=0; j<nombres.size(); j++){
        if (unique1[i]==nombres[j]){
          NewBlank bc1(nombresExt[j]);
          CommCount cc1(nombresExt[j]);
          empty = bc1.CountEmptylines();
          comm = cc1.CountCommlines();
          total = cc1.getTotal();
          iGlobal+=cc1.getiCount();
          bGlobal+=cc1.getbCount();
          mGlobal+=cc1.getmCount();
          dGlobal+=cc1.getdCount();
          tGlobal+=(total-comm-empty);
          found=true;
          iN=j;
        }
      }
      if (found){
        FileCount fileTest(name, tGlobal, iGlobal, bGlobal,
        dGlobal, mGlobal, tGlobal-bGlobal+dGlobal);
        if (fileTest.getType() == 0){
        cout << "   " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << 
      ", B=" << fileTest.getB() << ", D=" << fileTest.getD() << ", M="<< fileTest.getM() << ", A=" 
      << fileTest.getA() << endl;

      archSalida << "   " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << 
      ", B=" << fileTest.getB() << ", D=" << fileTest.getD() << ", M="<< fileTest.getM() << ", A=" 
      << fileTest.getA() << endl;


       totalLDC += fileTest.getT();
        }
        found= false;
      }
      iGlobal= mGlobal = tGlobal = dGlobal = bGlobal = 0;
    }
    cout << "------------------------------------------------" << endl;
    archSalida << "------------------------------------------------" << endl;



    cout << "CLASES NUEVAS: " << endl;
    archSalida << "CLASES NUEVAS: " << endl;

    
    for (int i=0; i<unique1.size(); i++){
      for (int j=0; j<nombres.size(); j++){
        if (unique1[i]==nombres[j]){
          NewBlank bc1(nombresExt[j]);
          CommCount cc1(nombresExt[j]);
          empty = bc1.CountEmptylines();
          comm = cc1.CountCommlines();
          total = cc1.getTotal();
          iGlobal+=cc1.getiCount();
          bGlobal+=cc1.getbCount();
          mGlobal+=cc1.getmCount();
          dGlobal+=cc1.getdCount();
          tGlobal+=(total-comm-empty);
          found=true;
          iN=j;
        }
      }
      if (found){
        FileCount fileTest(name, tGlobal, iGlobal, bGlobal,
        dGlobal, mGlobal, tGlobal-bGlobal+dGlobal);
        if (fileTest.getType() == 1){
        cout << "   " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << endl;
        archSalida << "   " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << endl;
       totalLDC += fileTest.getT();
        }
        found= false;
      }
      iGlobal= mGlobal = tGlobal = dGlobal = bGlobal = 0;
    }
    cout << "------------------------------------------------" << endl;
    archSalida << "------------------------------------------------" << endl;

    cout << "CLASES REUSADAS: " << endl;
    archSalida << "CLASES REUSADAS: " << endl;
    for (int i=0; i<unique1.size(); i++){
      for (int j=0; j<nombres.size(); j++){
        if (unique1[i]==nombres[j]){
          NewBlank bc1(nombresExt[j]);
          CommCount cc1(nombresExt[j]);
          empty = bc1.CountEmptylines();
          comm = cc1.CountCommlines();
          total = cc1.getTotal();
          iGlobal+=cc1.getiCount();
          bGlobal+=cc1.getbCount();
          mGlobal+=cc1.getmCount();
          dGlobal+=cc1.getdCount();
          tGlobal+=(total-comm-empty);
          found=true;
          iN=j;
        }
      }
      if (found){
        FileCount fileTest(name, tGlobal, iGlobal, bGlobal,
        dGlobal, mGlobal, tGlobal-bGlobal+dGlobal);
        if (fileTest.getType() == 2){
        cout << "   " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << 
      ", B=" << fileTest.getB()  << endl;
        archSalida << "   " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << 
      ", B=" << fileTest.getB()  << endl;
       totalLDC += fileTest.getT();
        }
        found= false;
      }
      iGlobal= mGlobal = tGlobal = dGlobal = bGlobal = 0;
    }
     cout << "------------------------------------------------" << endl;
     cout << "TOTAL DE LDC= " << totalLDC << endl;

     archSalida << "------------------------------------------------" << endl;
     archSalida << "TOTAL DE LDC=" << totalLDC;


     for (int i=0; i<unique1.size(); i++){
      for (int j=0; j<nombres.size(); j++){
        if (unique1[i]==nombres[j]){
          NewBlank bc1(nombresExt[j]);
          CommCount cc1(nombresExt[j]);
          empty = bc1.CountEmptylines();
          comm = cc1.CountCommlines();
          total = cc1.getTotal();
          iGlobal+=cc1.getiCount();
          bGlobal+=cc1.getbCount();
          mGlobal+=cc1.getmCount();
          dGlobal+=cc1.getdCount();
          tGlobal+=(total-comm-empty);
          found=true;
          iN=j;
        }
      }
      if (found){
        FileCount fileTest(name, tGlobal, iGlobal, bGlobal,
        dGlobal, mGlobal, tGlobal-bGlobal+dGlobal);
        if (fileTest.getType() == -1){
        cout << "******************Clase con error: " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << 
      ", B=" << fileTest.getB() << ", D=" << fileTest.getD() << ", M="<< fileTest.getM() << ", A=" 
      << fileTest.getA() << endl;
        archSalida << "******************Clase con error: " << nombres[iN] << ": T=" << fileTest.getT() <<", I=" << fileTest.getI() << 
      ", B=" << fileTest.getB() << ", D=" << fileTest.getD() << ", M="<< fileTest.getM() << ", A=" 
      << fileTest.getA() << endl;
       totalLDC += fileTest.getT();
        }
        found= false;
      }
      iGlobal= mGlobal = tGlobal = dGlobal = bGlobal = 0;
     }

     archSalida.close();

     //.d=12

    return 0; 
}