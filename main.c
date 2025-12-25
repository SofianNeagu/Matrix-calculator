#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
int main()
{
    int o;
    printf("Welcome to my matrix calculator! Please choose which of the following operations you would like to do:\n1.Matrix addition \n2.Matrix multiplication \n3.Transpose computation \n4.Determinant computation \n5.Inverse matrix computation \n");
    scanf("%d",&o);
    switch(o)
    {
    case 1:
    {
        int d1,d2,d3,d4;
        printf("Input the dimensions of the first matrix(rows and columns):");
        scanf("%d %d",&d1,&d2);
        printf("Input the first matrix:");
        Matrix a=creatematrix(d1,d2);
        inputmatrix(&a);
        printf("Input the dimensions of the second matrix(rows and columns):");
        scanf("%d %d",&d3,&d4);
        printf("Input the second matrix:");
        Matrix b=creatematrix(d3,d4);
        inputmatrix(&b);
        printf("The matrices are:\n");
        printmatrix(&a);
        printf("\n");
        printmatrix(&b);
        Matrix c=addmatrix(&a,&b);
        printf("The sum of these matrices is:\n");
        printmatrix(&c);
        freematrix(&a);
        freematrix(&b);
        freematrix(&c);
        break;
    }
    case 2:
    {
        int d1,d2,d3,d4;
        printf("Input the dimensions of the first matrix(rows and columns):");
        scanf("%d %d",&d1,&d2);
        printf("Input the first matrix:");
        Matrix a=creatematrix(d1,d2);
        inputmatrix(&a);
        printf("Input the dimensions of the second matrix(rows and columns):");
        scanf("%d %d",&d3,&d4);
        printf("Input the second matrix:");
        Matrix b=creatematrix(d3,d4);
        inputmatrix(&b);
        printf("The matrices are:\n");
        printmatrix(&a);
        printf("\n");
        printmatrix(&b);
        Matrix c=multiplymatrix(&a,&b);
        printf("The product of these matrices is:\n");
        printmatrix(&c);
        freematrix(&a);
        freematrix(&b);
        freematrix(&c);
        break;
    }
    case 3:
    {
        int d1,d2;
        printf("Input the dimensions of the matrix you want transposed(rows and columns):");
        scanf("%d %d",&d1,&d2);
        printf("Now input the matrix:");
        Matrix a=creatematrix(d1,d2);
        inputmatrix(&a);
        printf("Your matrix is:\n");
        printmatrix(&a);
        Matrix t=transpose(&a);
        printf("And its transposed is:\n");
        printmatrix(&t);
        freematrix(&a);
        freematrix(&t);
        break;
    }
    case 4:
    {
        int d1,d2;
        printf("Input the dimensions of the matrix(rows and columns):");
        scanf("%d %d",&d1,&d2);
        printf("Now input the matrix:");
        Matrix a=creatematrix(d1,d2);
        inputmatrix(&a);
        printf("Your matrix is:\n");
        printmatrix(&a);
        long double det=determinant(&a);
        printf("And its determinant is: %.2Lf", det);
        freematrix(&a);
        break;
    }
    case 5:
    {
        int d1,d2;
        printf("Input the dimensions of the matrix you want inversed(rows and columns):");
        scanf("%d %d",&d1,&d2);
        printf("Now input the matrix:");
        Matrix a=creatematrix(d1,d2);
        inputmatrix(&a);
        printf("Your matrix is:\n");
        printmatrix(&a);
        Matrix inv=inverse(&a);
        printf("And its inverse is:\n");
        printmatrix(&inv);
        freematrix(&a);
        freematrix(&inv);
        break;
    }
    default:
    {
        printf("Please enter a valid option(a number 1-5)");
        break;
    }
    }
    return 0;
}
