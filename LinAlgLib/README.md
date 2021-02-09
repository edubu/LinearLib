# Matrix library used for simple matrix multiplcation and transposes

## Examples
In Examples you can find main.cpp which contains examples of all of the uses.
 #### To use:
 1. Go into Examples directory in terminal
 2. Type 'make' into terminal
 3. Run executable name './main
 
 ## How to Use: 

### Supports use of doubles or ints:
Matrix\<double\><br>
or<br>
Matrix\<int\>

### Initialize Matrix:
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

### Functions:
Prints matrix to stdout <br>:
mat.print()

Returns transpose to given matrix
mat.transpose()

### Operators:
#### *
 Returns product of matrices:
 Matrix\<int\> = mat1 * mat2;
 
 Returns product of matrix and scalar:
 Matrix\<int\> = mat1 * 3;
 
 #### *=
 Multiplies given matrix by scalar:
 mat1 *= 3;
 
 Multiplies by given matrix:
 mat2 *= mat1;
