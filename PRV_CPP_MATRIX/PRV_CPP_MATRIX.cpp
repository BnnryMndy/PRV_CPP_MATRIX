// PRV_CPP_MATRIX.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int MATRIX_SIZE = 1000;

void MultiplyMatrix(double** matrixOne, double** matrixTwo, double** resultMatrix)
{

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

void ParallelMultiplyMatrix(double** matrixOne, double** matrixTwo, double** resultMatrix)
{
    #pragma omp parallel for num_threads(8)
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

void printMatrix(double** matrix)
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


void fillMatrix(double** matrix)
{

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = (double)rand() / 0.00001;
        }
    }
}

double shpoor(double** matrix)
{
    double result = 0;
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        result += matrix[i][i];
    }

    return result;
}

int main()
{
    cin >> MATRIX_SIZE;
    double** matrixOne = new double*[MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++)
    {   
        matrixOne[i] = new double[MATRIX_SIZE];
    }
    double** matrixTwo = new double* [MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        matrixTwo[i] = new double[MATRIX_SIZE];
    }
    double** resultMatrix = new double* [MATRIX_SIZE];
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        resultMatrix[i] = new double[MATRIX_SIZE];
    }


    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            resultMatrix[i][j] = 0;
        }
    }

    fillMatrix(matrixOne);
    fillMatrix(matrixTwo);

    auto t2 = clock();
    ParallelMultiplyMatrix(matrixOne, matrixTwo, resultMatrix);
    cout << (float)(clock() - t2) << "\n";

    auto t1 = clock();
    MultiplyMatrix(matrixOne, matrixTwo, resultMatrix);
    cout << (float)(clock() - t1) << "\n";
    if (MATRIX_SIZE < 5) printMatrix(resultMatrix);
    else cout << shpoor(resultMatrix);
    
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            resultMatrix[i][j] = 0;
        }
    }


}
