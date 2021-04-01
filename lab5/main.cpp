//.b=25
// Carlos Gerardo Herrera Cortina  A00821946
// Programa 5.
// incluyo clases
#include "Simpson.h"

//.i
int main(){
    double p=0.0, pUser=0.0; //.m
    double dof=0.0;
    double x = 1.0;
    double pAux = 0.0;
    bool isLow = false;
    double d = 0.5; 

    cout << "Introduce p: ";  //.m
    cin >> pUser;  //.m */
    if (!cin){
        cout << "Entrada inválida. Terminando programa." << endl;
        return 1;
    }
    if (p < 0  || p> 0.5 ){ //.m
        cout << "Error en dato, número incorrecto recibido. Terminando programa." << endl;
        return 1;
    }
    cout << "Introduce dof: ";
    cin >> dof;
    if (!cin){
        cout << "Entrada inválida. Terminando programa." << endl;
        return 1;
    }
    
    char dir;
    if (dof > 0 && floor(dof)==dof){
        Simpson simpson(x, dof); //.m
        pAux = simpson.calcSimpson();

        if (pAux > pUser){
            isLow = false;
            x-=d;
        }
        else{
            isLow = true;
            x+=d;
        }
        do{
            simpson.setXDOF(x, dof);
            p = pAux;
            pAux = simpson.calcSimpson();
            if (pAux > pUser) {
				if (isLow) 
					d /= 2;
				isLow = false;
			}
            else if (pAux < pUser) {
			    if (!isLow)
                    d/=2;
				isLow = true;
			}

            if (pAux < pUser) {
				x += d;
			}
			else {
				x -= d;
			}
        } while (abs(p - pAux) > 0.00000001);

        printf("  p = %.5f \n", pUser);
		cout << "dof = " << dof << endl;
		printf("  x = %.5f \n", x);
    }
    else{
        cout << "Error en dato, número incorrecto recibido. Terminando programa." << endl;
        return 1;
    }

    return 0; 
}