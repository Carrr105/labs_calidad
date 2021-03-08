// Carlos Gerardo Herrera Cortina  A00821946
// Programa 2.
#include <iostream>
#include <vector>
#include <algorithm>
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
   /*   NewBlank bc(name);
      CommCount cc(name);
      empty = bc.CountEmptylines();
      comm = cc.CountCommlines();
      total = cc.getTotal();
      code = total-comm-empty;
      files.push_back(FileCount(name, code, cc.getiCount(), cc.getbCount(),
       cc.getdCount(), cc.getmCount(), cc.getaCount(code)));*/

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
       totalLDC += fileTest.getT();
        }
        found= false;
      }
      iGlobal= mGlobal = tGlobal = dGlobal = bGlobal = 0;
    }
    cout << "------------------------------------------------" << endl;


    cout << "CLASES NUEVAS: " << endl;
    
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
       totalLDC += fileTest.getT();
        }
        found= false;
      }
      iGlobal= mGlobal = tGlobal = dGlobal = bGlobal = 0;
    }
    cout << "------------------------------------------------" << endl;

    cout << "CLASES REUSADAS: " << endl;
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
       totalLDC += fileTest.getT();
        }
        found= false;
      }
      iGlobal= mGlobal = tGlobal = dGlobal = bGlobal = 0;
    }
     cout << "------------------------------------------------" << endl;
     cout << "TOTAL DE LDC: " << totalLDC << endl;





  /*


    for(int i=0; i<numArch; i++){
      if (files[i].getType() == 0){
      cout << "   " << nombres[i] << ": T=" << files[i].getT() <<", I=" << files[i].getI() << 
      ", B= " << files[i].getB() << ", D=" << files[i].getD() << ", M="<< files[i].getM() << ", A=" 
      << files[i].getA() << endl;
      totalLDC += files[i].getT();
      }
    }
     cout << "------------------------------------------------" << endl;
    cout << "CLASES NUEVAS: " << endl;
     for(int i=0; i<numArch; i++){
     if (files[i].getType() == 1){
      cout << "   " << nombres[i] << ": T=" << files[i].getT() <<", I=" << files[i].getI() << 
      ", B= " << files[i].getB() << ", D=" << files[i].getD() << ", M="<< files[i].getM() << ", A=" 
      << files[i].getA() << endl;
      totalLDC += files[i].getT();
     }
    }
    cout << "------------------------------------------------" << endl;
    cout << "CLASES REUSADAS: " << endl;
    for(int i=0; i<numArch; i++){
     if (files[i].getType() == 2){
      cout << "   " << nombres[i] << ": T=" << files[i].getT() <<", I=" << files[i].getI() << 
      ", B= " << files[i].getB() << ", D=" << files[i].getD() << ", M="<< files[i].getM() << ", A=" 
      << files[i].getA() << endl;
      totalLDC += files[i].getT();
     }
    }
        cout << "------------------------------------------------" << endl;
       cout << "TOTAL DE LDC: " << totalLDC << endl;



    

    //for (int i=0; i<numArch; i++){

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
      && name.substr(name.find_last_of(".") + 1) != "cpp" && name.substr(name.find_last_of(".") + 1) != "c"
      && name.substr(name.find_last_of(".") + 1) != "h"){
        cout << "El archivo no es .txt" << endl;
        return 1;
      }

      fclose(f);


     // int empty=0, code=0, comm=0, total=0;
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


  //  }

  */
    return 0; 
}