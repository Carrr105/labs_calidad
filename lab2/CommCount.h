//.b=43
#include <fstream>
#include <iostream>
#include <regex>
using namespace std;
class CommCount{
    private:
    string name;
    int total;
    int iCount;
    int mCount;
    int baseCount;
    int baseCountGlobal;
    int deletedCount;
    int deletedCountGlobal;
    
    public: 
    //.i
    CommCount(){
        name = "";
        total=0;
        iCount=0;
        mCount=0;
        baseCount=0;
        baseCountGlobal=0;
        deletedCount=0;
        deletedCountGlobal=0;
    };
    //.i
    CommCount(string n){
        name = n;
        total=0;
        iCount=0;
        mCount=0;
        baseCount=0;
        baseCountGlobal=0;
        deletedCount=0;
        deletedCountGlobal=0;
    }

    // instruccion usada para quitar warnings de regex
    // se usa regex para detectar etiquetas dentro de strings
    // funciona, pero el compilador marca 2 warnings
    // asi que por simplicidad se eliminan
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunknown-escape-sequence"
    //.i
    int CountCommlines(){
        int comTotal = 0;
        string str;
        ifstream file (name);
        bool sameLine= true;
        int count=0;
        while (getline(file,str)){
            if (str.find("/*") != string::npos){
                comTotal++;
              //  cout << "found" << endl;   
                while (str.find("*/") == string::npos){ //.m
                    if(count!=0){
                    comTotal++;
                    sameLine=false;
                    }
                    getline(file,str) ;
                    count++;
                }
                count=0;
                if (!sameLine || str.find("*/") != string::npos){
                comTotal++;
       //         cout << str << endl;
                sameLine=true;
                }

            }
            
          else    if ( str.find("*/") != string::npos){
                comTotal++;

                         //       cout << "foundClose" << endl;
                             //   cout << str << endl;

           } 
            else if ( str.find("//") != string::npos){
                //.d=1
                smatch s, sm;
                regex e ("\\b("")([^//]*)");
                regex m (".*\/\/.m.*;");
                if ( (str.find(";") == string::npos)
                && (regex_search(str,s,e ))
                ){
                comTotal++;
                                //cout << str << endl;

                }
                if (str.find("//.i") != string::npos){
                    //cout << str << endl;
                    iCount++;
                    
                }
                if (str.find("//.m") != string::npos && !(regex_search(str,sm,m ))){
                    //cout << str << endl;
                    mCount++;
                }
                if (str.find("//.b=") != string::npos){
                    string numStr = "";
                    size_t numContainer = str.find("//.b=")+5;
                    while (isdigit(str[numContainer])) {
				        numStr.push_back(str[numContainer]);
				        numContainer++;
			        }
                    try {
                        baseCount = stoi(numStr);
                        baseCountGlobal += baseCount;
                    }
                    catch(exception e){
                       
                    }
                }
                if (str.find("//.d=") != string::npos){
                    string numStr = "";
                    size_t numContainer = str.find("//.d=")+5;
                    while (isdigit(str[numContainer])) {
				        numStr.push_back(str[numContainer]);
				        numContainer++;
			        }
                    try {
                        deletedCount = stoi(numStr);
                        deletedCountGlobal += deletedCount;
                    }
                    catch(exception e){

                    }
                }

            }
     }
     file.close();
        return comTotal;
    }
    
    #pragma GCC diagnostic pop

    //.i
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
    //.i
    int getiCount(){
        return iCount;
    }
    //.i
    int getmCount(){
        return mCount;
    }
    //.i
    int getbCount(){
        return baseCountGlobal;
    }
    //.i
    int getdCount(){
        return deletedCountGlobal;
    }
    //.i
    int getaCount(int code){
        return code-baseCountGlobal+deletedCountGlobal;
    }

};