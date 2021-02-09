#include <iostream>
#include <string>
#include "../Matrix.h"

using namespace std;

int main(){

    // Initialize 3x3 Matrix
    Matrix<int> mat3x3(3, 3, "matrix3x3.txt");
    cout << "3x3 Matrix: " << endl;
    mat3x3.print();

    // 3x3 square transpose
    cout << "3x3 Matrix Transpose: " << '\n';
    Matrix<int> mat3x3Transpose = mat3x3.transpose();
    mat3x3Transpose.print();

    // 2x3 non Matrix Transpose
    Matrix<int> mat2x3(2, 3, "matrix2x3.txt");
    cout << "2x3 Matrix: " << endl;
    mat2x3.print();
    mat2x3 = mat2x3.transpose();
    cout << "After transpose: " << endl;
    mat2x3.print();



    // Test for scalar multiplication operator
    Matrix<int> matMult(3, 3);
    cout << "Testing matrix scalar multiplication operator" << endl;
    cout << "Before Multplication by 3: " << endl;
    matMult.print();
    matMult = matMult * 3;
    cout <<"After Multiplication by 3: " << endl;
    matMult.print();

    // Test for matrix multiplication operator
    cout << "Testing matrix multiplication operator..." << endl <<endl;
    cout << "3x3 Matrix: " << endl;
    mat3x3.print();
    cout << "3x3 Matrix Transpose: " << endl;
    mat3x3Transpose.print();
    cout << "After m * m^T: " << endl;
    Matrix<int> testMult = mat3x3 * mat3x3Transpose;
    testMult.print();

    cout << "Multiply it by 3: " << endl;
    testMult *= 3;
    testMult.print();

    //Make identity matrix
    Matrix<int> i2mat(3, 3);
    i2mat *= 2;

    cout << "Multiply it by diagonal matrix of 2s: " << endl;
    testMult *= i2mat;
    testMult.print();

    return 0;
}