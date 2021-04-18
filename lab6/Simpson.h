//.b=
#include <iostream>
#include "CalculosF.h"

class Simpson{
    private:
    double p, W, x, E, numSeg, dof;
    
    public:
    Simpson(double, double);
    double calcSimpson();
    void setXDOF(double, double);
};

//.i
Simpson::Simpson(double xRec, double dofRec){
    E = 0.0000001;
    numSeg = 2.0;
    p = 0.0;
    x = xRec;
    dof = dofRec;
    W = x/numSeg;
}

//.i
void Simpson::setXDOF(double xRec, double dofRec){
    x = xRec;
    dof = dofRec;
}

//.i
double Simpson::calcSimpson(){
    CalculosF calc(dof, x);
    double sumaPares1, sumaImpares1, sumaPares2, sumaImpares2, p1, p2;

    do {
        p1= 0.0;
        p2=0.0;
        sumaImpares1=0.0;
        sumaPares1=0.0;
        W=x/numSeg;


        for (int i = 1; i < numSeg; i++) {
            if (i % 2 == 0) {
                sumaPares1+=2.0*calc.getF(i*W);
            }
            else {
                sumaImpares1+=4.0*calc.getF(i*W);
            }
	    } 

        p1 = (W/3.0) * ( calc.getF(0) + sumaImpares1 + sumaPares1 + calc.getF(x) );

        numSeg = numSeg * 2;
        sumaImpares2=0.0;
        sumaPares2=0.0;
        W=x/numSeg;


        for (int i = 1; i < numSeg; i++) {
		if (i % 2 == 0) {
			sumaPares2+=2.0*calc.getF(i*W);
		}
		else {
			sumaImpares2+=4.0*calc.getF(i*W);
		}
	    } 

        p2 = (W/3.0) * ( calc.getF(0) + sumaImpares2 + sumaPares2 + calc.getF(x) );

    } while ( abs(p2-p1) > E);
    numSeg = 2.0; // añadido puesto que el numero de segmentos seguia aumentando, lo cual hacia
                     // que la carga fuera muy pesada para el programa al aumentar el numero de
                     // vueltas

    if (p2-p1 <= E){
        p=p2;
        return p;
        
    }
    else{
        cout << "Error. terminando programa " << endl;
        return p;
    }

}