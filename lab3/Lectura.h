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
    Lectura(){
        name = "";
        xk=0;
        nCurrent=0;
        isFirstLine=true;
    }

    void lee(string fileName){
        name = fileName;
        ifstream file (name);
        string str;
        string numStr = "";
        size_t numContainer = 0;
        while (getline(file,str)){
            if (isFirstLine){
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    xk = stod(numStr);
                   // cout << xk << endl;
                    isFirstLine = false;
                }
                catch(exception e){
                    cout << "Se encontró algo que no es digíto" << endl;
                    file.close();
                    return;
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
                   // cout << "x: " << x[9] << endl;
                    numContainer++;
                }
                catch(exception e){
                    cout << "Se encontró algo que no es digíto" << endl;
                    file.close();
                    return;
                }
                numStr = "";
                while (isdigit(str[numContainer]) || str[numContainer] == '.') {
                    numStr.push_back(str[numContainer]);
                    numContainer++;
                }
                try {
                    nCurrent = stod(numStr);
                    y.push_back(nCurrent);
                   // cout << "y: " << y[9] << endl;
                    //cout << numStr << endl;
                    numContainer++;
                }
                catch(exception e){
                    cout << "Se encontró algo que no es digíto" << endl;
                    file.close();
                    return;
                }
                
            }
            numContainer = 0;
        }
    }

    vector<double> regresaX(){
        return x;
    }

    vector<double> regresaY(){
        return y;
    }

    double regresaXK(){
        return xk;
    }

};