#include <iostream>
#include <string>
#include "Matrix.h"

using namespace std;

int main(){

    string m1 = "matrix1.txt";
    Matrix mat1(3, 3, m1);

    Matrix mat2(3, 3);

    cout << "Matrix 1: " << '\n';
    mat1.print();

    cout << "Matrix 2: " << '\n';
    mat2.print();



    return 0;
}