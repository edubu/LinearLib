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
Prints matrix to stdout <br>
<t>mat.print()
