//.b=
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Lectura{
    private:
    string name;
    double xk;
    double nCurrent;
    vector<double> x, y;
    bool isFirstLine;

    public:
    Lectura();
    int lee(string);
    vector<double> regresaX();
    vector<double> regresaY();
    double regresaXK();
};

    //.i
    Lectura::Lectura(){
        name = "";
        xk=0.0;
        nCurrent=0;
        isFirstLine=true;
    }

    //.i
    int Lectura::lee(string fileName){
        name = fileName;
        ifstream file (name);
        string str;
        string numStr = "";
        size_t numContainer = 0;
        int xCount = 0;
        int yCount = 0;
        while (getline(file,str)){
            if (isFirstLine){
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    xk = stod(numStr);
                    isFirstLine = false;
                }
                catch(exception e){
                    cout << "Se encontró un xk que no es un número real >= 0" << endl;
                    file.close();
                    return 1;
                }
            }
            else{
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    nCurrent = stod(numStr);
                    x.push_back(nCurrent);
                    numContainer++;
                    xCount++;
                }
                catch(exception e){
                    cout << "Se encontró un valor que no es un número real >= 0 en el par número " << xCount << endl;
                    file.close();
                    return 1;
                }
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    nCurrent = stod(numStr);
                    y.push_back(nCurrent);
                    numContainer++;
                    yCount++;
                }
                catch(exception e){
                    cout << "Se encontró un valor que no es un número real >= 0 en el par número " << yCount << endl;
                    file.close();
                    return 1;
                }
                
            }
            numContainer = 0;
        }
        return 0;
    }

    //.i
    vector<double> Lectura::regresaX(){
        return x;
    }

    //.i
    vector<double> Lectura::regresaY(){
        return y;
    }

    //.i
    double Lectura::regresaXK(){
        return xk;
    }