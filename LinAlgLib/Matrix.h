#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


//Currently accepts doubles or ints

class InvalidMatrixDimensions : public std::exception {
    public:
        InvalidMatrixDimensions(string msg) : errorMsg(msg){}

        string what(){
            return errorMsg;
        }

    private:
        string errorMsg;
};

template <typename T>
class Matrix {
    public:
        // For txt file
        Matrix(int rows, int cols, string filename){
            this->rows = rows;
            this->cols = cols;

            matrix.resize(rows, vector<T>(cols, 0));

            ifstream fin;

            fin.open(filename);

            if(!fin.is_open()){
                cout << "Error opening: " << filename << endl;
            }

            T num;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    fin >> num;
                    matrix[i][j] = num;
                }
            }
        }

        // Makes identity matrix
        Matrix(int rows, int cols){
            this->rows = rows;
            this->cols = cols;
            matrix.resize(rows, vector<T>(cols, 0));

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(j == i){
                        matrix[i][j] = 1;
                    }
                }
            }
        }

        //Fills matrix with value
        Matrix(int rows, int cols, T value){
            this->rows = rows;
            this->cols = cols;
            matrix.resize(rows, vector<T>(cols, value));
        }

        // Assignment Operator
        Matrix<T> & operator=(const Matrix<T> &rhs){
            rows = rhs.rows;
            cols = rhs.cols;

            matrix.resize(rows, vector<T>(cols, 0));

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    matrix[i][j] = rhs.matrix[i][j];
                }
            }

            return *this;
        }

        // Copy Constructor
        Matrix(const Matrix<T> &other): rows(other.rows), cols(other.cols){

            matrix.resize(rows, vector<T>(cols, 0));
            
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }


        // Prints given matrix
        void print(){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cout << matrix[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

        // Returns matrix properties
        int getRows(){return rows;}
        int getCols(){return cols;}

        // Indexes to (row, col)
        T & operator()(int &row, int &col){
            return matrix[row][col];
        }

        // Ease of multiplying by scalar
        Matrix<T> & operator*(int val){
            
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    matrix[i][j] *= val;
                }
            }

            return *this;
        }

        // Ease of multiplying matric
        Matrix<T> operator*(Matrix<T> &other){
            try {
                if(cols != other.getRows()){

                    throw InvalidMatrixDimensions("Error: Invalid Matrix dimensions for multiplication");
                }
            }
            catch(InvalidMatrixDimensions &error){
                cout << error.what() << endl;
            }

            Matrix<T> newMatrix(rows, other.getCols(), 0);

            // For each point of new matrix
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < other.getCols(); j++){
                    for(int k = 0; k < cols; k++){
                        newMatrix(i, j) += matrix[i][k] * other(k, j);
                    }
                }
            }

            return newMatrix;
        }

        // Made for convienence in multiplying by scalar
        void operator*=(int val){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    matrix[i][j] *= val;
                }
            }
        }

        // Made for convienence in multiplying by matrix
        void operator*=(Matrix<T> &other){
            try {
                if(cols != other.getRows()){
                    cout << "Error: invalid dimensions for dot product" << endl;

                    throw InvalidMatrixDimensions("Invalid Matrix dimensions multiplication");
                }
            }
            catch(InvalidMatrixDimensions &error){
                cout << error.what() << endl;
            }

            Matrix<T> newMatrix(rows, other.getCols(), 0);

            // For each point of new matrix
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < other.getCols(); j++){
                    for(int k = 0; k < cols; k++){
                        newMatrix(i, j) += matrix[i][k] * other(k, j);
                    }
                }
            }

            matrix = newMatrix.matrix;
        }

        Matrix<T>  transpose(){
            Matrix<T> matTranspose(cols, rows);

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    matTranspose(j, i) = matrix[i][j];
                }
            }

            return matTranspose;
        }





    private:

    vector<vector<T> > matrix;
    int rows;
    int cols;
};

#endif