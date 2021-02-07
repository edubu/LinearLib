#include <iostream>
#include <string>
#include "Matrix.h"
#include "LinAlg.h"

using namespace std;

int main(){

    // Initialize 3x3 Matrices
    Matrix<int> mat1(3, 3, "matrix1.txt");
    Matrix<int> mat2(3, 3);

    // 2x3 matrix
    Matrix<int> mat3(2, 3, "matrix3.txt");

    cout << "Matrix 1: " << '\n';
    mat1.print();

    cout << "Matrix 2: " << '\n';
    mat2.print();

    cout << "Matrix 3: " << '\n';
    mat3.print();

    Linalg lin;

    // 4x4 square transpose
    cout << "Matrix 1 Transpos: " << '\n';
    Matrix<int> mat1Transpose = lin.transpose(mat1);
    mat1Transpose.print();

    //Non-square matrix transpose
    cout << "Matrix 3 Transpose: " << '\n';
    Matrix<int> mat3Transpose = lin.transpose(mat3);
    mat3Transpose.print();

    //mat2 is identity matrix so mat1 should return
    cout << "Matrix 1 * Matrix 2: " << '\n';
    Matrix<int> mat1Mult = lin.mult(mat1, mat2);
    mat1Mult.print();

    // Non-square matrices for testing matrix multiplication
    cout << "2x3 Matrix A: " << '\n';
    Matrix<int> matA(2, 3, "matrixA.txt");
    matA.print();

    cout << "3x2 Matrix B: " << '\n';
    Matrix<int> matB(3, 2, "matrixB.txt");
    matB.print();

    Matrix<int> matAB = lin.mult(matA, matB);
    Matrix<int> matBA = lin.mult(matB, matA);

    cout << "Matrix A * Matrix B: " << '\n';
    matAB.print();

    cout << "Matrix B * Matrix A: " << '\n';
    matBA.print();

    cout << "3 * Matrix 1: " << '\n';
    lin.mult(mat1, 3);
    mat1.print();





    return 0;
}