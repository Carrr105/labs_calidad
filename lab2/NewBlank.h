#include <fstream>
#include <stdlib.h>
#include <stdio.h>  
#include <iostream>

using namespace std;

class NewBlank{
    private:
    string name;
    
    public: 
    //.i
    NewBlank(){
        name = "";
    };
    
    //.i
    NewBlank(string n){
        name = n;
    }

    //.i
    int CountEmptylines(){
        int total = 0;
        FILE* file = fopen(name.c_str(), "r");
        char buf[1000], *pointer;
        while (!feof(file)) {
            fgets(buf, 1000, file);
            pointer=buf;
            while (*pointer== ' ' || *pointer == '\t'){
                pointer++; // sigue recorriendo el archivo
            }
            if (*pointer=='\r'){
                pointer++;
            }

            if (*pointer=='\n' ){
                total++;
            }

            if (*pointer=='}' || *pointer=='{'){
                pointer++;
                if (*pointer=='\r' || *pointer=='\n'){
                        total++;

                }
                if (*pointer==';'){
                    pointer++;
                    if (*pointer=='\r' || *pointer=='\n'){
                        total++;

                    }
                }
            }
        }
        fclose(file);
        return total;
    }
};