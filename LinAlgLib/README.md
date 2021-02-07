# Matrix library used for simple matrix multiplcation and transposes

## Supports use of doubles or ints:
Matrix\<double\><br>
or<br>
Matrix\<int\>

## Initialize Matrix:
 Reads from file in format:<br>
1 2 <br>
3 4<br>
Matrix\<T\> mat(int rows, int cols, string filename);

or

Creates identity matrix:<br>
Matrix\<T\> mat(int rows, int cols);

or

Creates matrix with all positions filled with val:<br>
Matrix\<T\> mat(int rows, int cols, T val);

## Functions:
Returns transpose to input matrix:<br>
transpose(Matrix\<T\> mat);

Returns matrix product of mat1 and mat2 in order mat1 * mat2 (since matrix multiplication isnt commutative):<br>
mult(Matrix\<T\> mat1, Matrix\<T\> mat2);

Performs scalar multiplication on matrix:<br>
mult(Matrix\<T\> mat1, T val);
