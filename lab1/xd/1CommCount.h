#include <fstream>
#include <iostream>
using namespace std;
class CommCount{
    private:
    string name;
    int total;
    
    public: 
    CommCount(){
        name = "";
        total=0;
    };
    
    CommCount(string n){
        name = n;
    }

    int CountCommlines(){
        int comTotal = 0;
        string str;
        ifstream file (name);
        while (getline(file,str)){
            if (str.find("/*") != string::npos){
                comTotal++;
                while (getline(file,str) && str.find("*/") == string::npos){
                    comTotal++;
                }
                comTotal++;
            }
            else if ( str.find("*/") != string::npos){
                comTotal++;
            }
            else if ( str.find("//") != string::npos){
                comTotal++;
            }
     }
     file.close();
        return comTotal;
    }

    int getTotal(){
        string str;
        ifstream file (name);
        while (!file.eof()){
            getline(file, str);
            total++;
    }
    file.close();
    return total;
    }
};