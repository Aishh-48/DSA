#include <stdio . h>
#include <stdlib.h>

 int* allocateMatrix(int rows, int cols) {
return (int*)ma lloc (rows * cols * sizeof (int));
 }
void inputMatrix(int* matrix, int rows, int cols) {
for (int i = 0; i< rows; i++) {
for (int j = 0; j < cols; j+t){
printf("Enter element [%d] [%d]: ", i, j);
Scanf("%d", (matrix t i * cols + j));
}
}
}
void printMatrix(int* matrix, int rows, int cols) {
for (int i = 0; i < rows; itt) {
for (int j = 0: j < cols: jtt) {
print f("%d".
* "(matrix + i * cols + j));
}
printf("\n");
}
}
 int* multiplyMatrices (int* matrix1, int* matrix2, int rows1, int cols1, int cols2)
{
int* result = allocateMatrix(rows1, cols2) ;
for (int i = 0; i < rows1; itt) {
for (int j = 0; j < cols2: jt+) {
*(result i * cols2+j) = 0;
for (int k = 0; k< cols1; kt+t){
(result + i * cols2 + j) +=((matrix1 *I *cols1 + k)) *
(*(matrix2 + k * cols2+ j));
}
}
}
return result;
}
int main() {
int rows1, cols1, rows2, cols2;

printf("Enter number of rows and columns for the first matrix: ");
scanf("%d %d", &rows1, &cols1);

printf("Enter number of rows and columns for the second matrix: ");
Scanf("%d %d", &rows2, &cols2);

if (cols1 != rows2) {
printf("Error: Matrix multiplication is not possible with the given
dimens ions . \n") ;
return -1;
}
