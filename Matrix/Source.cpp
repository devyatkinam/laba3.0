#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int r, c;
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> r >> c;

    vector<vector<int>> m(r, vector<int>(c));

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    vector<int> s(c, 0); 

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (m[i][j] < 0 && m[i][j] % 2 != 0) {
                s[j] += abs(m[i][j]);
            }
        }
    }

    for (int i = 0; i < c - 1; i++) {
        for (int j = 0; j < c - i - 1; j++) {
            if (s[j] > s[j + 1]) {
                int t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;

                for (int k = 0; k < r; k++) {
                    int v = m[k][j];
                    m[k][j] = m[k][j + 1];
                    m[k][j + 1] = v;
                }
            }
        }
    }

    cout << "Полученная матрица:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    int snegc = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (m[j][i] < 0) {
                snegc += m[j][i];
                break;
            }
        }
    }

    cout << "Сумма элементов в столбцах с отрицательными элементами: " << snegc << endl;

    return 0;
}
