#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Part2_Null(int** a, const int rowCount, const int colCount);
void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo) {
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo) {
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void InputRow(int** a, const int rowNo, const int colCount, int colNo) {
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo) {
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo) {
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
int Part1_Plus(int** a, const int rowCount, const int colCount, int i, int j, int& result) {
	if (a[i][j] > 0) {
		if (i < result) {
			result = i;
			Part1_Plus(a, rowCount, colCount, 0, i + 1, result);
			cout << result;
			cout << endl;
		}
	}
	else if (j < colCount - 1) {
		Part1_Plus(a, rowCount, colCount, j + 1, 0, result);
	}
	else if (i < rowCount - 1) {
		Part1_Plus(a, rowCount, colCount, j, i + 1, result);
	}
	return result;
}

void Part2_Null(int** a, const int rowCount, const int colCount) {
	for (int n = 0; n < rowCount; n++) {
		int prom = 0;
		for (int k = 0; k < colCount; k++) {
			if (!a[n][k] == 0) {
				break;
			}
			else {
				prom++;
				if (prom == rowCount) {
					delete[] a[n];
					int** tmp = new int* [rowCount - 1];
					int tmpI = 0;
					for (int i = 0; i < rowCount; ++i)
						if (i != n)
							tmp[tmpI++] = a[i];
					delete[] a;
					a = tmp;
					cout << "Array after deleting " << n << "-th row\n";
					cout << endl;
					for (int i = 0; i < rowCount; i++) {
						for (int j = 0; j < colCount; j++)
							cout << setw(4) << a[i][j];
						cout << endl;
					}
					cout << endl;
				}
			}
		}
	}
	for (int k = 0; k < colCount; k++) {
		int prom = 0;
		for (int n = 0; n < rowCount; n++) {
			if (!a[n][k] == 0) {
				break;
			}
			else {
				prom++;
				if (prom == colCount) {

				}
			}
		}
	}
}
int main() {
	srand((unsigned)time(NULL));
	int Low = -21;
	int High = 24;

	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	//CreateRows(a, rowCount, colCount, Low, High, 0);
	InputRows(a, rowCount, colCount, 0);
	PrintRows(a, rowCount, colCount, 0);
	int result = rowCount;
	Part1_Plus(a, rowCount, colCount, 0, 0, result);
	Part2_Null(a, rowCount, colCount);
	cout << endl;
	for (int i = 0; i < rowCount; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}