#include <fstream>
using namespace std;
class BlankCount{
    private:
    string name;
    
    public: 
    BlankCount(){
        name = "";
    };
    
    BlankCount(string n){
        name = n;
    }

    int CountEmptylines(){
        int total = 0;
        char caracter='\n';
        bool isEmptyCurrently = true;
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
            if (*pointer=='\n'){
                total++;
            }
        }
        fclose(file);
        return total+1; // falta contar la ultima linea, se agrega
    }
};