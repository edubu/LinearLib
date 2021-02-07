#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


//Currently accepts doubles or ints

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
                    matrix[i][j] = *(rhs.matrix[i][j]);
                }
            }
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



    private:

    vector<vector<T> > matrix;
    int rows;
    int cols;
};

#endif