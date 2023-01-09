#include "Functions.h"
#include <iostream>

using namespace std;

template <typename T>
void swap(T* a, T* b)
{
	T* tmp = a;
	a = b;
	b = tmp;
}

void createArr(int n)
{
	int* arr = new int[n];

	cout << "Введите массив:\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	int* pa = &arr[0], * pla = &arr[n - 1];
	cout << "Первый элемент: " << *pa << "\nПоследний элемент: " << *pla << "\nМеняем местами!\n";
	swap(*pa, *pla);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int sortDesc(double arr[12])
{
	int moves = 0;
	for (int i = 0; i < 11; ++i) {
		bool isSorted = true;
		for (int j = 0; j < 11 - i; ++j) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				++moves;
				isSorted = false;
			}
		}
		if (isSorted) break;
	}
	return moves;
}

int* negFirst(int* arr, int n)
{
	int* newArr = new int[n];
	int l = 0, r = n - 1, negc = 0, posc = 0;
	while (l < n) {
		if (arr[l] < 0) {
			newArr[negc] = arr[l];
			++negc;
		}
		if (arr[r] >= 0) {
			newArr[n - posc - 1] = arr[r];
			++posc;
		}
		++l; --r;
	}
	return newArr;
}

int swapHalfs(double arr[14])
{
	int moves = 0; 
	for (int i = 0; i < 7; ++i) {
		swap(arr[i], arr[i + 7]);
		++moves;
	}
	return moves;
}

int locMins(int* arr, int n)
{
	int count = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
			++count;
	}
	return count;
}

int sumPart(int* row, int n)
{
	bool zero = false;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (row[i] == 0) {
			if (!zero)
				zero = true;
			else
				return sum;
		}
		else if (zero)
			sum += row[i];
	}
	return sum;
}

void orderArr(int arr[15])
{
	for (int i = 0; i < 14; ++i) {
		bool isSorted = true;
		for (int j = 0; j < 14 - i; ++j) {
			if ((arr[j] >= 0 && arr[j + 1] < 0) ||
				(arr[j] >= 0 && arr[j + 1] > arr[j]) ||
				(arr[j] < 0 && arr[j + 1] < 0 && arr[j] > arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
				isSorted = false;
			}
		}
		if (isSorted) break;
	}
}

void swapMaxs(int* arr1, int* arr2)
{
	int n, m, maxi_1 = -1, maxi_2 = -1, max1 = -10000000, max2 = -10000000;
	cout << "Введите размерность первого массива: ";
	cin >> n;
	arr1 = new int[n];
	cout << "Введите первый массив из " << n << " элементов:\n";
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i];
		if (arr1[i] > max1) {
			max1 = arr1[i];
			maxi_1 = i;
		}
	}

	cout << "Введите размерность второго массива: ";
	cin >> m;
	arr2 = new int[m];
	cout << "Введите второй массив из " << m << " элементов:\n";
	for (int i = 0; i < m; ++i) {
		cin >> arr2[i];
		if (arr2[i] > max2) {
			max2 = arr2[i];
			maxi_2 = i;
		}
	}

	swap(arr1[maxi_1], arr2[maxi_2]);

	cout << "\nНовые массивы:\n";
	for (int i = 0; i < n; ++i)
		cout << arr1[i] << " ";
	cout << endl;

	for (int i = 0; i < m; ++i)
		cout << arr2[i] << " ";
	cout << endl;
}

void moveCols(int** matr, int n, int m)
{
	for (int j = 1; j < m; ++j) {
		for (int i = 0; i < n; ++i)
			swap(matr[i][0], matr[i][j]);
	}
}

void findRowsBySum(int** matr, int n, int m)
{
	int* sumByRow = new int[n], maxsum = -100000000, minsum = 100000000;

	for (int i = 0; i < n; ++i) {
		int sum = 0; 
		for (int j = 0; j < m; ++j)
			sum += matr[i][j];

		if (sum > maxsum)
			maxsum = sum;

		if (sum < minsum)
			minsum = sum;

		sumByRow[i] = sum;
	}

	cout << "Строки с максимальной суммой элементов: ";
	for (int i = 0; i < n; ++i)
		if (sumByRow[i] == maxsum)
			cout << (i + 1) << " ";
	
	cout << "\nСтроки с минимальной суммой элементов: ";
	for (int i = 0; i < n; ++i)
		if (sumByRow[i] == minsum)
			cout << (i + 1) << " ";
	
	cout << endl;
}
