#include <stdio.h>

#define INDEX(mat, row, col) mat[mat[1] * row + col + 2]

void inputMat(int *m)
{
    printf("Enter elements %d elements row major order for the matrix:\n", m[0] * m[1]);
    for (int i = 0; i < m[0]; i++)
    {
        for (int j = 0; j < m[1]; j++)
        {
            scanf("%d", &INDEX(m, i, j));
        }
    }
}

void printMat(int *m)
{
    for (int i = 0; i < m[0]; i++)
    {
        for (int j = 0; j < m[1]; j++)
        {
            printf("%d ", INDEX(m, i, j));
        }
        putchar('\n');
    }
}

void addMat(int *m1, int *m2)
{
    if (m1[0] != m2[0] || m1[1] != m2[1])
    {
        printf("Error cannot add 2 matrices of mismatching dimentions: %d x %d and %d x %d\n", m1[0], m1[1], m2[0], m2[1]);
        return;
    }

    for (int i = 0; i < m1[0]; i++)
    {
        for (int j = 0; j < m1[1]; j++)
        {
            INDEX(m1, i, j) += INDEX(m2, i, j);
        }
    }
}

void mulMat(int *m1, int *m2, int *dest)
{
    if (m1[1] != m2[0]) // dimention mismatch
    {
        printf("Error cannot multiply matrices with dimentions: %d x %d and %d x %d\n", m1[0], m1[1], m2[0], m2[1]);
        return;
    }
    
    if (m1[0] != dest[0] || m2[1] != dest[1])   // destination dimention mismatch
    {
        printf("Error destination not big enough to store matrix\n");
        return;
    }
    
    for (int i = 0; i < m1[0]; i++)
    {
        for (int j = 0; j < m2[1]; j++)
        {
            INDEX(dest, i, j) = 0;
            for (int k = 0; k < m1[1]; k++)
            {
                INDEX(dest, i, j) += INDEX(m1, i, k) * INDEX(m2, k, j);
            }
        }
    }
}

int traceMat(int *m)
{
    if (m[0] != m[1]) // not square matrix
    {
        printf("Error trace only exists for square matrices current order: %d x %d\n", m[0], m[1]);
        return -999;
    }

    int trace = 0;
    for (int i = 0; i < m[0]; i++)
    {
        trace += INDEX(m, i, i);
    }

    return trace;
}

void transposeMat(int *src, int *dest)
{
    if (src[0] != dest[1] || src[1] != dest[0])
    {
        printf("Error not enough space in destination matrix to store transpose orders: %d x %d and %d x %d\n", src[0], src[1], dest[0], dest[1]);
        return;
    }

    for (int i = 0; i < src[0]; i++)
    {
        for (int j = 0; j < src[1]; j++)
        {
            INDEX(dest, j, i) = INDEX(src, i, j);
        }
    }
}

int main()
{
    int running = 1;
    while (running)
    {
        int ch;
        printf("1) Add\n2) Trace\n3) Multiply\n4) Transpose\n5) Quit\n> ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("Enter dimentions of the matrices (row x col): ");
            int row, col;
            scanf("%d %d", &row, &col);

            int m1[row * col + 2];
            m1[0] = row;
            m1[1] = col;
            inputMat(m1);
            
            int m2[row * col + 2];
            m2[0] = row;
            m2[1] = col;
            inputMat(m2);

            addMat(m1, m2);
            printf("Output:\n");
            printMat(m1);
        }
        break;

        case 2:
        {
            printf("Enter the size of square matrix: ");
            int d;
            scanf("%d", &d);

            int m[d * d + 2];
            m[0]  = m[1] = d;   // square matrix
            inputMat(m);

            printf("Trace of matrix: %d\n", traceMat(m));
        }
        break;

        case 3:
        {
            printf("Enter dimentions of matrix 1(row x col): ");
            int r1, c1;
            scanf("%d %d", &r1, &c1);

            printf("Enter dimentions of matrix 2(row x col): ");
            int r2, c2;
            scanf("%d %d", &r2, &c2);

            int m1[r1 * c1 + 2];
            m1[0] = r1;
            m1[1] = c1;
            inputMat(m1);
            
            int m2[r2 * c2 + 2];
            m2[0] = r2;
            m2[1] = c2;
            inputMat(m2);
            
            int dest[r1 * c2 + 2];
            dest[0] = r1;
            dest[1] = c2;

            mulMat(m1, m2, dest);
            printf("Output:\n");
            printMat(dest);
        }
        break;

        case 4:
        {
            printf("Enter dimentions of matrix(row x col): ");
            int row, col;
            scanf("%d %d", &row, &col);

            int m1[row * col + 2];
            m1[0] = row;
            m1[1] = col;
            inputMat(m1);

            int m2[row * col + 2];  // transposed destination
            m2[0] = col;
            m2[1] = row;

            transposeMat(m1, m2);
            printf("Output:\n");
            printMat(m2);
        }
        break;

        case 5:
        running = 0;
        break;

        default:
            printf("Unknown choice\n");
            break;
        }
    }

    return 0;
}