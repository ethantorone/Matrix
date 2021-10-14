#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

int main() {

    Matrix mat(2,2);

    mat.at(0,0) = 1;
    mat.at(0,1) = 2;
    mat.at(1,0) = 3;
    mat.at(1,1) = 4;

    mat.printMatrix();

    //Matrix mat2 = mat.add(mat);
    //mat2.printMatrix();

    //Matrix mat3 = mat.subtract(mat2);
    //mat3.printMatrix();

    Matrix mat4(2,3);
    mat4.at(0,0) = 1;
    mat4.at(0,1) = 2;
    mat4.at(0,2) = 3;
    mat4.at(1,0) = 4;
    mat4.at(1,1) = 5;
    mat4.at(1,2) = 6;

    mat4.printMatrix();

    //Matrix mat5 = mat.multiply(mat4);
    //mat5.printMatrix();

    Matrix mat6 = mat4.t();
    mat6.printMatrix();

    return EXIT_SUCCESS;

}
