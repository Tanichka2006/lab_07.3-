#include <iostream>
#include <iomanip>
using namespace std;

void CreateMatrix(int** matrix, int rows, int cols);
void PrintMatrix(int** matrix, int rows, int cols);
int CountRowsWithZero(int** matrix, int rows, int cols);
void FindColumnWithLongestSeries(int** matrix, int rows, int cols, int& column, int& maxSeriesLength);

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    CreateMatrix(matrix, rows, cols);
    cout << "Matrix:" << endl;
    PrintMatrix(matrix, rows, cols);

    int zeroRows = CountRowsWithZero(matrix, rows, cols);
    cout << "Number of rows with at least one zero element: " << zeroRows << endl;

    int column = 0, maxSeriesLength = 0;
    FindColumnWithLongestSeries(matrix, rows, cols, column, maxSeriesLength);
    cout << "Column with the longest series of identical elements: " << column << " (length = " << maxSeriesLength << ")" << endl;

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

// Функція для заповнення матриці з клавіатури
void CreateMatrix(int** matrix, int rows, int cols) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// Функція для виведення матриці
void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Функція для підрахунку кількості рядків з нульовими елементами
int CountRowsWithZero(int** matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                count++;
                break;
            }
        }
    }
    return count;
}

// Функція для знаходження стовпця з найдовшою серією однакових елементів
void FindColumnWithLongestSeries(int** matrix, int rows, int cols, int& column, int& maxSeriesLength) {
    for (int j = 0; j < cols; j++) {
        int currentSeriesLength = 1;
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] == matrix[i - 1][j]) {
                currentSeriesLength++;
                if (currentSeriesLength > maxSeriesLength) {
                    maxSeriesLength = currentSeriesLength;
                    column = j;
                }
            }
            else {
                currentSeriesLength = 1;
            }
        }
    }
}
