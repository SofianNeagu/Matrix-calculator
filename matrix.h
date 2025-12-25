#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
typedef struct
{
    int rows;
    int columns;
    long double** data;
} Matrix;
Matrix creatematrix(int rows, int columns);
void inputmatrix(Matrix* m);
void freematrix(Matrix *m);
void printmatrix(const Matrix *m);
Matrix addmatrix(const Matrix *a,const Matrix *b);
Matrix multiplymatrix(const Matrix *a,const Matrix *b);
Matrix transpose(const Matrix *m);
long double determinant(const Matrix *m);
Matrix inverse(const Matrix *m);
#endif // MATRIX_H_INCLUDED
