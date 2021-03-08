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
    }

    vector <string> nombresExt = nombres;


    for (int i=0; i<numArch; i++){
    //  cout << nombres[i] << endl;
    size_t lastdot = nombres[i].find_last_of(".");
    if (lastdot == string::npos){ 
      // do nothing
       
    }
    else {
      nombres[i] = nombres[i].substr(0, lastdot);
    }
   // cout << nombres[i] << endl;
  
    }


    vector<string> unique1 = nombres;

    ofstream archSalida;
    archSalida.open("ConteoLDC.txt");

    //sort(unique1.begin(), unique1.end());
    unique1.erase(unique(unique1.begin(), unique1.end()), unique1.end());

   /* for (int i=0; i<unique1.size(); i++){
      cout << unique1[i] << endl;
    } */

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

     archSalida.close();

    return 0; 
}