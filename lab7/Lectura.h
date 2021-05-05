//.b=79
#include <fstream>
#include <iostream>
#include <vector>
//.d=1
using namespace std;

class Lectura{
    private:
    string name;
    double wk, xk, yk;
    double nCurrent;
    vector<double> w, x, y, z;
    bool isFirstLine;

    public:
    Lectura();
    int lee(string);
    vector<double> regresaX();
    vector<double> regresaY();
    vector<double> regresaW();
    vector<double> regresaZ();
    double regresaXK();
    double regresaWK();
    double regresaYK();
};

    //.i
    Lectura::Lectura(){
        name = "";
        xk = wk = yk = 0.0;
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
        int wCount = 0;
        int xCount = 0;
        int yCount = 0;
        int zCount = 0;
        while (getline(file,str)){
            if (isFirstLine){
                // lee wk
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    wk = stod(numStr);
                    numContainer++;
                }
                catch(exception e){
                    cout << "Se encontró un wk que no es un número real >= 0" << endl;
                    file.close();
                    return 1;
                }
                // lee xk
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    xk = stod(numStr);
                    numContainer++;
                }
                catch(exception e){
                    cout << "Se encontró un xk que no es un número real >= 0" << endl;
                    file.close();
                    return 1;
                }
                // lee yk
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    yk = stod(numStr);
                    isFirstLine = false;
                }
                catch(exception e){
                    cout << "Se encontró un yk que no es un número real >= 0" << endl;
                    file.close();
                    return 1;
                }

            }
            else{
                // lee w
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    nCurrent = stod(numStr);
                    w.push_back(nCurrent); //.m
                    numContainer++;
                    wCount++; //.m
                }
                catch(exception e){
                    cout << "Se encontró un valor que no es un número real >= 0 en el par número " << wCount << endl;  //.m
                    file.close();
                    return 1;
                }
                // lee x
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    nCurrent = stod(numStr);
                    x.push_back(nCurrent);  //.m
                    numContainer++;
                    xCount++;  //.m
                }
                catch(exception e){
                    cout << "Se encontró un valor que no es un número real >= 0 en el cuádruplo número " << xCount << endl;  //.m
                    file.close();
                    return 1;
                }
                // lee y
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
                    cout << "Se encontró un valor que no es un número real >= 0 en el cuádruplo número " << yCount << endl;
                    file.close();
                    return 1;
                }
                // lee z
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    nCurrent = stod(numStr);
                    z.push_back(nCurrent);
                    numContainer++;
                    zCount++;
                }
                catch(exception e){
                    cout << "Se encontró un valor que no es un número real >= 0 en el par número " << zCount << endl;
                    file.close();
                    return 1;
                }
                
                
            }
            numContainer = 0;
        }
        file.close();
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
    vector<double> Lectura::regresaW(){
        return w;
    }

    //.i
    vector<double> Lectura::regresaZ(){
        return z;
    }

    //.i
    double Lectura::regresaXK(){
        return xk;
    }

    //.i
    double Lectura::regresaWK(){
        return wk;
    }

    //.i
    double Lectura::regresaYK(){
        return yk;
    }