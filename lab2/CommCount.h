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
                while (str.find("*/") == string::npos){
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
                    
                    baseCount = stoi(numStr);
                    baseCountGlobal += baseCount;
                }
                if (str.find("//.d=") != string::npos){
                    string numStr = "";
                    size_t numContainer = str.find("//.d=")+5;
                    while (isdigit(str[numContainer])) {
				        numStr.push_back(str[numContainer]);
				        numContainer++;
			        }
                    deletedCount = stoi(numStr);
                    deletedCountGlobal += deletedCount;
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

    int getiCount(){
        return iCount;
    }

    int getmCount(){
        return mCount;
    }

    int getbCount(){
        return baseCountGlobal;
    }

    int getdCount(){
        return deletedCountGlobal;
    }

    int getaCount(int code){
        return code-baseCountGlobal+deletedCountGlobal;
    }



};