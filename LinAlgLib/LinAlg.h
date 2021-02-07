#ifndef LINALG_H
#define LINALG_H

#include "Matrix.h"

using namespace std;

class Linalg {
    public:

    Linalg(){};

    // Returns transpose of matrix
    template <typename T>
    Matrix<T> transpose(Matrix<T> &mat){
        Matrix<T> matTranspose(mat.getCols(), mat.getRows());

        for(int i = 0; i < mat.getRows(); i++){
            for(int j = 0; j < mat.getCols();j++){
                matTranspose(j, i) = mat(i, j);
            }
        }

        return matTranspose;

    }

    // Returns product of matrices
    template <typename T>
    Matrix<T> mult(Matrix<T> &m1, Matrix<T> &m2){
        if(m1.getCols() != m2.getRows()){
            cout << "Error: invalid dimensions for dot product" << endl;
            exit(1);
        }

        Matrix<T> newMatrix(m1.getRows(), m2.getCols(), 0);

        // For each point of new matrix
        for(int i = 0; i < m1.getRows(); i++){
            for(int j = 0; j < m2.getCols(); j++){
                for(int k = 0; k < m1.getCols(); k++){
                    newMatrix(i, j) += m1(i, k) * m2(k, j);
                }
            }
        }

        return newMatrix;
    }

    // performs scalar multiplication by factor val
    template <typename T>
    void mult(Matrix<T> &mat, T val){
        for(int i = 0; i < mat.getRows(); i++){
            for(int j = 0; j < mat.getCols(); j++){
                mat(i, j) *= val;
            }
        }
    }


    private:


};

#endif