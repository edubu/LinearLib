# Matrix library used for simple matrix multiplcation and transposes

## Supports use of doubles or ints:
Matrix\<double\>
or
Matrix\<int\>

## Initialize Matrix:
 Reads from file in format:
1 2
3 4
Matrix\<T\> mat(int rows, int cols, string filename);

or

Creates identity matrix:
Matrix\<T\> mat(int rows, int cols);

or

Creates matrix with all positions filled with val:
Matrix\<T\> mat(int rows, int cols, T val);

## Functions:
Returns transpose to input matrix:
transpose(Matrix\<T\> mat);

Returns matrix product of mat1 and mat2 in order mat1 * mat2 (since matrix multiplication isnt commutative):
mult(Matrix\<T\> mat1, Matrix\<T\> mat2);

Performs scalar multiplication on matrix:
mult(Matrix\<T\> mat1, T val);
