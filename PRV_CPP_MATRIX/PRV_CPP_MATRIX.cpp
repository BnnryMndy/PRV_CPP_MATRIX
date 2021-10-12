// PRV_CPP_MATRIX.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#define  MATRIX_SIZE 4

using namespace std;

void MultiplyMatrix(
    double(matrixOne)[MATRIX_SIZE][MATRIX_SIZE],
    double(matrixTwo)[MATRIX_SIZE][MATRIX_SIZE],
    double(resultMatrix)[MATRIX_SIZE][MATRIX_SIZE]
) {

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            for (int k = 0; k < MATRIX_SIZE; k++)
            {
                resultMatrix[i][j] += matrixOne[i][k] * matrixTwo[k][j];
            }
        }
    }
}

void printMatrix(double(matrix)[MATRIX_SIZE][MATRIX_SIZE])
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << matrix[i][j] << " \t";
        }
        if (i < MATRIX_SIZE - 1) cout << "\n\n";
    }
}


void fillMatrix(double(matrix)[MATRIX_SIZE][MATRIX_SIZE])
{

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = (double)rand() / 0.00001;
        }
    }
}

int main()
{
    double matrixOne[MATRIX_SIZE][MATRIX_SIZE];
    double matrixTwo[MATRIX_SIZE][MATRIX_SIZE];
    double resultMatrix[MATRIX_SIZE][MATRIX_SIZE];

    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        for (size_t j = 0; j < MATRIX_SIZE; j++)
        {
            resultMatrix[i][j] = 0;
        }
    }

    fillMatrix(matrixOne);
    fillMatrix(matrixTwo);

    MultiplyMatrix(matrixOne, matrixTwo, resultMatrix);

    if(MATRIX_SIZE < 5) printMatrix(resultMatrix);
}
