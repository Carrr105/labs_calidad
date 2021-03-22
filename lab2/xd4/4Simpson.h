#include <iostream>
#include "CalculosF.h"

class Simpson{
    private:
    double p, W, x, E, numSeg, dof;
    
    public:
    Simpson(double, double);
    void calcSimpson();

};

//.i
Simpson::Simpson(double xRec, double dofRec){
    E = 0.0001;
    numSeg = 2.0;
    p = 0.0;
    x = xRec;
    dof = dofRec;
    W = x/numSeg;
}

//.i
void Simpson::calcSimpson(){
    CalculosF calc(dof, x);
    double sumaPares, sumaImpares, p1, p2;

    do {
        p1= 0.0;
        p2=0.0;
        sumaImpares=0.0;
        sumaPares=0.0;
        W=x/numSeg;

        for (int i=1; i<=numSeg-1; i+=2.0){
            sumaImpares+=4.0*calc.getF(i*W);
        }
        for (int i=2; i<=numSeg-2; i+=2.0){
            sumaPares+=2.0*calc.getF(i*W);
        }

        p1 = (W/3.0) * ( calc.getF(0) + sumaImpares + sumaPares + calc.getF(x) );

        numSeg = numSeg * 2;
        sumaImpares=0.0;
        sumaPares=0.0;
        W=x/numSeg;

        for (int i=1; i<=numSeg-1; i+=2.0){
            sumaImpares+=4.0*calc.getF(i*W);
        }
        for (int i=2; i<=numSeg-2; i+=2.0){
            sumaPares+=2.0*calc.getF(i*W);
        }

        p2 = (W/3.0) * ( calc.getF(0) + sumaImpares + sumaPares + calc.getF(x) );

    } while ( abs(p2-p1) > E);

    if (p2-p1 <= E){
        p=p2;
        printf("  x = %.5f \n", x);
        cout << "dof = " << dof << endl;
        printf("  p = %.5f \n", p);
    }
    else{
        cout << "Error. terminando programa " << endl;
    }

}