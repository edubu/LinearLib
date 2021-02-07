#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Matrix {
    public:
        // For txt file
        Matrix(int rows, int cols, string filename){
            this->rows = rows;
            this->cols = cols;

            matrix.resize(rows, vector<int>(cols, 0));

            ifstream fin;

            fin.open(filename);

            if(!fin.is_open()){
                cout << "Error opening: " << filename << endl;
            }

            int num;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cin >> num;
                    matrix[i][j] = num;
                }
            }
        }

        // Makes identity matrix
        Matrix(int rows, int cols){
            this->rows = rows;
            this->cols = cols;
            matrix.resize(rows, vector<int>(cols, 0));

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(j == i){
                        matrix[i][j] = 1;
                    }
                }
            }
        }

        void print(){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cout << matrix[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }

    private:

    vector<vector<int> > matrix;
    int rows;
    int cols;
};

#endif