#include <fstream>
#include <stdlib.h>
#include <stdio.h>  
#include <iostream>

using namespace std;

class NewBlank{
    private:
    string name;
    
    public: 
    NewBlank(){
        name = "";
    };
    
    NewBlank(string n){
        name = n;
    }

    int CountEmptylines(){
        int total = 0;
      //  bool isLast = true;
        FILE* file = fopen(name.c_str(), "r");
        char buf[1000], *pointer;
        while (!feof(file)) {
            fgets(buf, 1000, file);
            pointer=buf;
            while (*pointer== ' ' || *pointer == '\t'){
              //  isLast=false;
                pointer++; // sigue recorriendo el archivo
            }
            if (*pointer=='\r'){
                pointer++;
            }

            if (*pointer=='\n' ){
            //    isLast=true;
           // cout << "entro" << endl;
                total++;
             //   cout << pointer << endl;
            }

            if (*pointer=='}' || *pointer=='{'){
                pointer++;
                if (*pointer=='\r'){
                        total++;

                }
                if (*pointer==';'){
                    pointer++;
                    if (*pointer=='\r'){
                        total++;

                    }
                }
            }
        }
  //      char charFinal = pointer[strlen(pointer)-1]; //obtengo el ultimo caracter
    //    if (charFinal=='\n' /*|| !isLast */)  total++; // checo si hay una linea extra
        fclose(file);
        return total;
    }
};