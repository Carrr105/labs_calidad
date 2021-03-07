#include <fstream>
#include <iostream>
#include <regex>
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
        bool sameLine= true;
        int count=0;
        while (getline(file,str)){
            if (str.find("/*") != string::npos){
                comTotal++;
                cout << str << endl;   
                while (str.find("*/") == string::npos){
                    if(count!=0){
                    comTotal++;
                    cout << str << endl;
                    sameLine=false;
                    }
                    getline(file,str) ;
                    count++;

                }
                count=0;
                if (!sameLine){
                comTotal++;
                cout << str << endl;
                sameLine=true;
                }

            }
            
            else if ( str.find("*/") != string::npos){
                comTotal++;
                                cout << str << endl;

           } 
            else if ( str.find("//") != string::npos){
                smatch s;
                regex e ("\\b("")([^//]*)");
                if ( (str.find(";") == string::npos)
                && (regex_search(str,s,e ))
                ){
                comTotal++;
                                cout << str << endl;

                }
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