#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using namespace std;

typedef unsigned int uint;


Matrix::Matrix(uint rows, uint cols) { // constructor (all elements initialized to 0)
    mat = new double*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new double[cols];
    } //for
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++) {
            mat[i][j] = 0;
        } //for
    } //for
    this->rows = rows;
    this->columns = cols;
} //Matrix

Matrix::Matrix(const Matrix & m) { // copy constructor
    mat = new double*[m.numRows()];
    for (int i = 0; i < m.numRows(); i++) {
        mat[i] = new double[m.numCols()];
    } //for
    for (uint i = 0; i < m.numRows(); i++) {
        for (uint j = 0; j < m.numCols(); j++) {
            mat[i][j] = m.at(i,j);
        } //for
    } //for
    this->rows = m.numRows();
    this->columns = m.numCols();
} //Matrix
Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    } //for
    delete[] mat;
} // destructor

Matrix Matrix::add(double s) const { // add scalar to this matrix
    Matrix result(*this);
    for (uint i = 0; i < this->numRows(); i++) {
        for (uint j = 0; j < this->numCols(); j++) {
            result.at(i,j) = this->at(i,j) + s;
        } //for
    } //for
    return result;
} //add
Matrix Matrix::add(const Matrix & m) const { // add this matrix and another matrix
    Matrix result(*this);
    for (uint i = 0; i < this->numRows(); i++) {
        for (uint j = 0; j < this->numCols(); j++) {
            result.at(i,j) = this->at(i,j) + m.at(i,j);
        } //for
    } //for
    return result;
} //add

Matrix Matrix::subtract(double s) const {// subtract scalar from this matrix
    Matrix result(*this);
    for (uint i = 0; i < this->numRows(); i++) {
        for (uint j = 0; j < this->numCols(); j++) {
            result.at(i,j) = this->at(i,j) - s;
        } //for
    } //for
    return result;
} //subtract
Matrix Matrix::subtract(const Matrix & m) const { // subtract another matrix from this matrix
    Matrix result(*this);
    for (uint i = 0; i < this->numRows(); i++) {
        for (uint j = 0; j < this->numCols(); j++) {
            result.at(i,j) = this->at(i,j) - m.at(i,j);
        } //for
    } //for
    return result;
} //subtract

Matrix Matrix::multiply(double s) const { // multiply this matrix by a scaler
    Matrix result(*this);
    for (uint i = 0; i < this->numRows(); i++) {
        for (uint j = 0; j < this->numCols(); j++) {
            result.at(i,j) = this->at(i,j) * s;
        } //for
    } //for
    return result;
} //multiply
Matrix Matrix::multiply(const Matrix & m) const { // multiply this matrix by another matrix
    Matrix result(this->numRows(), m.numCols());
    for (int i = 0; i < result.numRows(); i++) {        //result's rows
        for (int j = 0; j < result.numCols(); j++) {    //result's cols
            double sum = 0;
            for (int k = 0; k < this->numCols(); k++) { //1st's cols / 2nd's rows
                sum += this->at(i,k) * m.at(k,j);       //multiplies 1st[i,k] * 2nd[k,j]
            } //for
            result.at(i,j) = sum;
        } //for
    } //for
    return result;
} //multiply

Matrix Matrix::divide(double s) const { // divide this matrix by a scalar
    Matrix result(*this);
    for (uint i = 0; i < this->numRows(); i++) {
        for (uint j = 0; j < this->numCols(); j++) {
            result.at(i,j) = this->at(i,j) / s;
        } //for
    } //for
    return result;
} //divide
Matrix Matrix::t() const { // transpose of this matrix
    Matrix result(this->numCols(), this->numRows());
    for (int i = 0; i < this->numRows(); i++) {       //this's rows
        for (int j = 0; j < this->numCols(); j++) {   //this's cols
            result.at(j,i) = this->at(i,j);
        } //for
    } //for
    return result;
} //t

const uint Matrix::numRows() const {return rows;} // returns the number of rows
const uint Matrix::numCols() const {return columns;} // returns the number of cols

double & Matrix::at(uint row, uint col) {return mat[row][col];} // get/set element at row,col
const double & Matrix::at (uint row, uint col) const {return mat[row][col];}

void Matrix::printMatrix() {
    for (int i = 0; i < this-> numRows(); i++) {
        for (int j = 0; j < this->numCols(); j++) {
            cout << mat[i][j] << ", ";
        } //for
        cout << endl;
    } //for
} //printMatrix

// get element at row,col (when using a const object)
