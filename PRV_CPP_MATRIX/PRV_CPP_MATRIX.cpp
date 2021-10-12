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
    //double resultMatrix[MATRIX_SIZE][MATRIX_SIZE];

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
            matrix[i][j] = (double)rand()/0.00001;
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


    


    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
