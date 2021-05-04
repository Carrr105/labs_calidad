#include <algorithm>
using namespace std;

class GJordan{
    private:
        double b0;
        double b1;
        double b2;
        double b3;
    public:
        GJordan();
        void gaussJordan(double[4][5]);
        double getb0();
        double getb1();
        double getb2();
        double getb3();
};

//.i
GJordan :: GJordan(){
    b0 = b1 = b2 = b3 = 0.0;
}

//.i
double GJordan :: getb0(){
    return b0;
}

//.i
double GJordan :: getb1(){
    return b1;
}

//.i
double GJordan :: getb2(){
    return b2;
}

//.i
double GJordan :: getb3(){
    return b3;
}

//.i
void GJordan :: gaussJordan(double matrix[4][5]){
    double aux = 0;
    int k = 0, c;
    for (int i=0; i<4; i++){
        if (matrix[i][i]==0){
            c = 1;
            while ((i + c) < 4 && matrix[i+c][i] == 0 ){
                c++;
            }
            if (i + c == 4){
                break;
            }
            for (int j = i; k<=4; k++ ){
                swap(matrix[j][k], matrix[j+c][k]);
            }
        }

        for (int j = 0; j < 4; j++){

            if (i != j){
                aux = matrix[j][i] / matrix[i][i];
                for (k=0; k<= 4; k++ ){
                    matrix [j][k] = matrix[j][k] - matrix[i][k] * aux;
                }
            }
        }
    }
    b0 = matrix[0][4] / matrix[0][0];
    b1 = matrix[1][4] / matrix[1][1];
    b2 = matrix[2][4] / matrix[2][2];
    b3 = matrix[3][4] / matrix[3][3];
}
