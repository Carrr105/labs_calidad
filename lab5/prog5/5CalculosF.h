//.b=32
#include <math.h>
using namespace std;

class CalculosF{
    private:
    double x, dof;
    
    public:
    CalculosF(double, double);
    double getF(double);
    double getGamma(double);
    double getGammaInt(double);
    double getGammaDouble(double);
};

//.i
CalculosF::CalculosF(double dofRec, double xRec){
    dof = dofRec;
    x = xRec;
}

//.i
double CalculosF::getF(double x){
    return  ( ( getGamma((dof+1.0)/2.0 ) ) / (sqrt(dof*2*acos(0.0)) * getGamma(dof / 2.0)) ) * pow(1.0+(  (x*x)/dof  ), -(dof+1.0)/2.0);
}

//.i
double CalculosF::getGamma(double x){
    if (floor(x)==x){
        return getGammaInt(x-1);
    }
    else{
        return getGammaDouble(x);
    }
}

//.i
double CalculosF::getGammaInt(double x){
    if(x > 1){
        return x * getGammaInt(x - 1);
    }
    else{
        return 1;
    }
}

//.i
double CalculosF::getGammaDouble(double x){
    if (x==1){
        return 1;
    }
    if (x==.5){
        return sqrt(2*acos(0.0));
    }
    return (x-1)*getGammaDouble(x-1);
}
