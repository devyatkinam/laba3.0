#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int r, c;
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> r >> c;

    vector<vector<int>> mx(r, vector<int>(c));

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mx[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int sum_ij = i + j;
            if (sum_ij % 2 == 0) {
                int m = i;
                int n = j;
                if (i % 2 == 0) {
                    if (j == c - 1) {
                        m = i + 1;
                        n = 0;
                    }
                    else {
                        m = i;
                        n = j + 1;
                    }
                }
                else {
                    if (j == 0) {
                        m = i + 1;
                        n = c - 1;
                    }
                    else {
                        m = i;
                        n = j - 1;
                    }
                }
                int temp = mx[i][j];
                mx[i][j] = mx[m][n];
                mx[m][n] = temp;
            }
        }
    }

    cout << "Измененная матрица:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mx[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> sneg(c, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mx[i][j] < 0) {
                sneg[j] = 1;
            }
        }
    }

    for (int j = 0; j < c; j++) {
        if (sneg[j] == 1) {
            int col_sum = 0;
            for (int i = 0; i < r; i++) {
                col_sum += mx[i][j];
            }
            cout << "Сумма элементов в столбце " << j << " с отрицательными элементами: " << col_sum << endl;
        }
    }

    return 0;
}
