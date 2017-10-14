#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<stdint.h>


void print_matrix(int64_t size_column, int64_t size_line, int64_t** a)
{
    for (int64_t col = 0; col < size_column; col++)
    {
        for (int64_t line = 0; line < size_line; line++)
        {
            printf("%lli ", a[col][line]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_array(int64_t size, int64_t *array)
{
    for (int64_t st = 0; st < size; st++)
    {
        printf("%lli ", array[st]);
    }
    printf("\n\n");
}

void randomarray(int64_t size_line, int64_t* a)
{
    for (int64_t st = 0; st < size_line; st++)
    {
        a[st] = rand() % 100;
    }
}

int64_t** make_array(int64_t size_column, int64_t size_line)
{
    int64_t** array = (int64_t**)malloc(size_column * sizeof(int64_t*));
    for (int64_t i = 0; i < size_column; i++)
    {
        array[i] = (int64_t*)malloc(size_line * sizeof(int64_t));
        randomarray(size_line, array[i]);
    }
    return array;
}

void** matrix_multiplication(int64_t M, int64_t N, int64_t K, int64_t** a, int64_t** b, int64_t** c)
{
    int64_t i=0;
    int64_t j=0;
    for (int64_t k = 0; k < N; k++)
    {
        for (int64_t m = 0; m < K; m++)
        {
            if(i == M)
            {
                i=0;
            }
            if(j == K)
            {
                j=0;
            }
            c[k][m]=a[i][k]*b[k][j];
            i++;
            j++;
        }
    }
}


void free_function(int64_t size_column, int64_t** a)
{
    for (int64_t i = 0; i < size_column; i++)
    {
        free(a[i]);
    }
    free(a);
}


int64_t main()
{

    int64_t **a;
    int64_t M = 0;
    int64_t N = 0;

    printf("Enter size of column for a-matrix\n");

    scanf("%lli", &M);

    printf("Enter size of line for a-matrix\n");

    scanf("%lli", &N);
    srand(time(NULL));
    a = make_array(M, N);
    print_matrix(M, N, a);

    int64_t **b;
    int64_t K = 0;
    printf("Enter size of line for b-matrix\n");
    scanf("%lli", &K);
    b = make_array(N, K);
    print_matrix(N, K, b);

    int64_t **c;
    c = make_array(N, K);
    matrix_multiplication(M, N, K, a, b, c);
    print_matrix(N, K, c);
    free_function(M, a);
    free_function(N, b);
    free_function(N, c);
    system("pause");

    return 0;

}