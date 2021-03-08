#include <fstream>
#include <stdlib.h>
#include <stdio.h>  
#include <iostream>
using namespace std;
class FileCount{
    private:
    string name;
    int tipo; //0 para base, 1 para nueva, 2 para reusada. error con -1
    int b;
    int t;
    int i;
    int m;
    int d;
    int a;
    
    public: 
    FileCount(){
        name = "";
    };
    
    FileCount(string n, int tA, int iA, int bA, int dA, int mA, int aA){
        name = n;
        b = bA;
        t = tA;
        i = iA;
        m = mA;
        d = dA;
        a = aA;
    }

    int getType(){
        if (b>0 &&(m>0 || d>0 || a>0)){
            return 0; // base
        }
        if (b==0 && m==0 && d==0 && a>0){
            return 1; // nueva
        }
        if (b>0 && m==0 && d==0 && a==0){
            return 2; // reusada
        }
        return -1; // error
    }

    int getI(){
        return i;
    }

    int getB(){
        return b;
    }

    int getT(){
        return t;
    }

    int getM(){
        return m;
    }

    int getD(){
        return d;
    }

    int getA(){
        return a;
    }


};