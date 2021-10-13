// PRV_CPP_MATRIX.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

size_t MATRIX_SIZE = 1000;

void MultiplyMatrix(double** matrixOne, double** matrixTwo, double** resultMatrix)
{

    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        for (size_t j = 0; j < MATRIX_SIZE; j++)
        {
            for (size_t k = 0; k < MATRIX_SIZE; k++)
            {
                resultMatrix[i][j] += matrixOne[i][k] * matrixTwo[k][j];
            }
        }
    }
}

void printMatrix(double** matrix)
{
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        for (size_t j = 0; j < MATRIX_SIZE; j++)
        {
            cout << matrix[i][j] << " \t";
        }
        if (i < MATRIX_SIZE - 1) cout << "\n\n";
    }
}


void fillMatrix(double** matrix)
{

    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        for (size_t j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = (double)rand() / 0.00001;
        }
    }
}

double shpoor(double** matrix)
{
    double result = 0;
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        result += matrix[i][i];
    }

    return result;
}

int main()
{
    cin >> MATRIX_SIZE;
    double** matrixOne = new double*[MATRIX_SIZE];
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {   
        matrixOne[i] = new double[MATRIX_SIZE];
    }
    double** matrixTwo = new double* [MATRIX_SIZE];
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        matrixTwo[i] = new double[MATRIX_SIZE];
    }
    double** resultMatrix = new double* [MATRIX_SIZE];
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        resultMatrix[i] = new double[MATRIX_SIZE];
    }


    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        for (size_t j = 0; j < MATRIX_SIZE; j++)
        {
            resultMatrix[i][j] = 0;
        }
    }

    fillMatrix(matrixOne);
    fillMatrix(matrixTwo);
    auto t1 = clock();
    MultiplyMatrix(matrixOne, matrixTwo, resultMatrix);
    cout << (float)(clock() - t1) << "\n";
    if (MATRIX_SIZE < 5) printMatrix(resultMatrix);
    else cout << shpoor(resultMatrix);
}
