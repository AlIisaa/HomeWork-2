#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    // 1
    int a = 5, b = 10;
    cout << "1.\na = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "Меняем местами!\na = " << a << ", b = " << b << "\n";

    // 2
    int n;
    cout << "\n2.\nвведите число элементов в массиве: ";
    cin >> n;
    createArr(n);

    // 3
    double** p = 0;
    p = new double*;
    *p = new double;
    **p = 2;
    cout << "\n3.\n**p = " << **p << endl;
    delete* p, p;

    // 4
    double arr1[12];
    cout << "\n4.\nВведите массив из 12 элементов:\n";
    for (int i = 0; i < 12; ++i)
        cin >> arr1[i];
    cout << "Количество перестановок: " << sortDesc(arr1) << endl;
    for (int i = 0; i < 12; ++i)
        cout << arr1[i] << " ";
    cout << endl;

    // 5
    int arr2[] = { 1, -2, 3, -4, 5, -6, 0 },
        arr3[] = { -2, -3, -4, 0, 1, 2, 3, -9 },
        arr4[] = { 1, 2, 3, 4, -5, -6, -7, -8 };
    int* arr5 = negFirst(arr2, 7);
    cout << "\n5.\nИсходный массив:\n";
    for (int i = 0; i < 7; ++i)
        cout << arr2[i] << " ";
    cout << "\nНовый массив:\n";
    for (int i = 0; i < 7; ++i)
        cout << arr5[i] << " ";
    delete[] arr5;

    arr5 = negFirst(arr3, 8);
    cout << "\n\nИсходный массив:\n";
    for (int i = 0; i < 8; ++i)
        cout << arr3[i] << " ";
    cout << "\nНовый массив:\n";
    for (int i = 0; i < 8; ++i)
        cout << arr5[i] << " ";
    delete[] arr5;

    arr5 = negFirst(arr4, 8);
    cout << "\n\nИсходный массив:\n";
    for (int i = 0; i < 8; ++i)
        cout << arr4[i] << " ";
    cout << "\nНовый массив:\n";
    for (int i = 0; i < 8; ++i)
        cout << arr5[i] << " ";
    cout << endl;
    delete[] arr5;

    // 6
    cout << "\n6.\nВведите массив из 14 элементов:\n";
    double arr6[14];
    for (int i = 0; i < 14; ++i)
        cin >> arr6[i];
    cout << "\nКоличество перестановок: " << swapHalfs(arr6) << "\nИзмененный массив:\n";
    for (int i = 0; i < 14; ++i)
        cout << arr6[i] << " ";
    cout << endl;

    // 7
    int arr7[] = { 1, -2, 3, -4, 5, -6, 0 };
    cout << "\n7.\nИсходный массив:\n";
    for (int i = 0; i < 7; ++i)
        cout << arr7[i] << " ";
    cout << "\nКоличество локальных минимумов: " << locMins(arr7, 7) << endl;

    // 8
    int matrix[5][4] = { {0, 2, 3, 0},
                         {4, 0, 6, 0},
                         {0, 8, 0, 9},
                         {0, 0, 11, 12},
                         {13, 0, 0, 15} };
    cout << "\n8.\nИсходная матрица:\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << "\nСуммы элементов, заключенных между двумя нулями:\n";
    for (int i = 0; i < 5; ++i)
        cout << "Строка " << i << ": " << sumPart(matrix[i], 4) << endl;

    // 9
    int arr9[15];
    cout << "\n9.\nВведите массив из 15 элементов:\n";
    for (int i = 0; i < 15; ++i)
        cin >> arr9[i];
    orderArr(arr9);
    for (int i = 0; i < 15; ++i)
        cout << arr9[i] << " ";
    cout << endl;

    // 10
    cout << "\n10.\n";
    int* arr10_1 = nullptr, * arr10_2 = nullptr;
    swapMaxs(arr10_1, arr10_2);
    
    // 11
    int** matr11 = new int* [5];

    cout << "\n11.\nВведите исходную матрицу 5x5:\n";
    for (int i = 0; i < 5; ++i) {
        matr11[i] = new int[5];
        for (int j = 0; j < 5; ++j)
            cin >> matr11[i][j];
    }

    moveCols(matr11, 5, 5);

    cout << "\nСдвинем столбцы матрицы на 1 вправо:\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << matr11[i][j] << " ";
        cout << endl;
    }

    // 12
    cout << "\n12.\n";
    findRowsBySum(matr11, 5, 5);

}
