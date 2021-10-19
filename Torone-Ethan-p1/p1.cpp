#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

int main() {

    Matrix Mat1(2,2);

    Mat1.at(0,0) = 1;
    Mat1.at(0,1) = 2;  // 1, 2
    Mat1.at(1,0) = 3;  // 3, 4
    Mat1.at(1,1) = 4;

    cout << "Mat1: " << endl;
    Mat1.printMatrix();

    Matrix Mat2 = Mat1.add(Mat1);           // 2, 4
    cout << "Mat2 = Mat1.add(Mat1): " << endl; // 6, 8
    Mat2.printMatrix();

    Matrix Mat3 = Mat2.add(1);             // 3, 5
    cout << "Mat3 = Mat2.add(1): " << endl;// 7, 9
    Mat3.printMatrix();

    Matrix Mat4 = Mat1.subtract(Mat2);     // -1, -2
    cout << "Mat4 = Mat.subtract(Mat2):" << endl; // -3, -4
    Mat4.printMatrix();

    Matrix Mat5 = Mat4.subtract(1);              // -2, -3
    cout << "Mat5 = Mat4.subtract(1): " << endl; // -4, -5
    Mat5.printMatrix();

    Matrix Mat6(2,3); //1, 2
    Mat6.at(0,0) = 1; //3, 4
    Mat6.at(0,1) = 2; //1, 2, 3
    Mat6.at(0,2) = 3; //4, 5, 6
    Mat6.at(1,0) = 4;
    Mat6.at(1,1) = 5;
    Mat6.at(1,2) = 6;

    cout << "Mat6: " << endl;
    Mat6.printMatrix();

    Matrix Mat7 = Mat1.multiply(Mat6);      // 9, 12, 15
    cout << "Mat7 = Mat1.multiply(Mat6): " << endl; //19, 26, 33
    Mat7.printMatrix();

    Matrix Mat8 = Mat7.multiply(2);              // 18, 24, 30
    cout << "Mat8 = Mat7.multiply(2): " << endl; // 38, 52, 66
    Mat8.printMatrix();

    Matrix Mat9 = Mat8.t();             // 18, 38
    cout << "Mat9: Mat8.t(): " << endl; // 24, 52
    Mat9.printMatrix();                 // 30, 66

    cout << "Mat9 has " << Mat9.numRows() << " rows." <<endl;
    cout << "Mat9 has " << Mat9.numCols() << " columns." <<endl;

    return EXIT_SUCCESS;
}
