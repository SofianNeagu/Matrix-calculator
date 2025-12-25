#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
Matrix creatematrix(int rows, int columns)
{
    Matrix m;
    m.rows=rows;
    m.columns=columns;
    m.data=calloc(rows,sizeof(long double*));
    if(!m.data)
    {
        puts("Memory allocation failed!");
        exit(1);
    }
    for(int i=0; i<rows; i++)
    {
        m.data[i]=calloc(columns,sizeof(long double));
        if(!m.data[i])
        {
            puts("Memory allocation failed!");
            exit(1);

        }

    }
    return m;
}
void inputmatrix(Matrix* m)
{
    for(int i=0; i<m->rows; i++)
    {
        for(int j=0; j<m->columns; j++)
            scanf("%Lf",&(m->data[i][j]));
    }

}
void freematrix(Matrix* m)
{
    for(int i=0; i<m->rows; i++)
        free(m->data[i]);

    free(m->data);
}
void printmatrix(const Matrix *m)
{
    for(int i=0; i<m->rows; i++)
    {
        for(int j=0; j<m->columns; j++)
            printf("%.2Lf ",m->data[i][j]);
        printf("\n");
    }
}
Matrix addmatrix(const Matrix *a,const Matrix *b)
{
    if((a->rows != b->rows) || (a->columns != b->columns))
    {
        puts("Matrix addition is invalid, sizes are different");
        exit(1);

    }
    Matrix c=creatematrix(a->rows,a->columns);
    for(int i=0; i<c.rows; i++)
    {
        for(int j=0; j<c.columns; j++)
            (c.data[i][j])=(a->data[i][j])+(b->data[i][j]);
    }
    return c;
}
Matrix multiplymatrix(const Matrix *a,const Matrix *b)
{
    if(a->columns != b->rows)
    {
        puts("Matrix multiplication is invalid due to sizes");
        exit(1);
    }
    Matrix d=creatematrix(a->rows,b->columns);
    for(int i=0; i<d.rows; i++ )
    {
        for(int j=0; j<d.columns; j++)
        {
            d.data[i][j]=0;
            for(int k=0; k<a->columns; k++)
                d.data[i][j]+=(a->data[i][k])*(b->data[k][j]);
        }

    }
    return d;
}
Matrix transpose(const Matrix *m)
{
    Matrix t=creatematrix(m->columns,m->rows);
    for(int i=0; i<t.rows; i++)
    {
        for(int j=0; j<t.columns; j++)
        {
            t.data[i][j]=(m->data[j][i]);
        }

    }
    return t;
}
long double determinant(const Matrix* m)
{
    if(m->rows != m->columns)
    {
        puts("Matrix is non-square, determinant is not defined");
        exit(1);
    }
    long double sum=0;
    if(m->rows==1)
        return m->data[0][0];
    for(int i=0; i<m->columns; i++)
    {
        Matrix minor=creatematrix((m->rows-1),(m->columns-1));
        for(int j=0; j<minor.rows; j++)

        {
            int t=0;
            for(int k=0; k<m->columns; k++)
            {
                if(k==i)
                    continue;
                minor.data[j][t]=m->data[j+1][k];
                t++;
            }

        }
        long double sign=(i%2==0)? 1.0 : -1.0;
        sum+=m->data[0][i]*sign*determinant(&minor);
        freematrix(&minor);
    }
    return sum;
}
Matrix inverse(const Matrix* m)
{
    long double det=determinant(m);
    if(fabsl(det)<LDBL_EPSILON)
    {
        puts("This matrix's determinant is equal to 0, inverse cannot be computed");
        exit(1);
    }
    Matrix inverse=creatematrix(m->rows,m->columns);
    Matrix cofactor=creatematrix(m->rows,m->columns);
    long double mult= (long double)1/det;
    for(int i=0; i<m->rows; i++)
    {
        for(int j=0; j<m->columns; j++)
        {
            Matrix minor=creatematrix((m->rows)-1,(m->columns)-1);
            int rindex=0;
            for(int row=0; row<m->rows; row++)
            {
                if(row==i)
                    continue;
                int cindex=0;
                for(int column=0; column<m->columns; column++)
                {
                    if(column==j)
                        continue;
                    minor.data[rindex][cindex]=m->data[row][column];
                    cindex++;

                }
                rindex++;

            }
            long double sign=((i+j)%2==0)? 1.0 : -1.0;
            cofactor.data[i][j]=sign*determinant(&minor);
            freematrix(&minor);
        }
    }
    Matrix adjugate=transpose(&cofactor);
    freematrix(&cofactor);
    for(int s=0; s<inverse.rows; s++)
    {
        for(int t=0; t<inverse.columns; t++)
        {
            inverse.data[s][t]=mult*adjugate.data[s][t];

        }

    }
    freematrix(&adjugate);
    return inverse;
}
