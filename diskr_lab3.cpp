#include <iostream>
#include <vector>

using namespace std;

// Функція для обчислення факторіалу
int factorial(int number) {
    int fact = 1;
    for (int i = 2; i <= number; ++i) {
        fact *= i;
    }
    return fact;
}

// Функція для обчислення кількості розміщень без повторень
int permutationCount(int n, int r) {
    int result = 1;
    for (int i = 0; i < r; ++i) {
        result *= (n - i);
    }
    return result;
}

// Функція для обчислення чисел Стерлінга другого роду та чисел Белла
void stirlingAndBell(int i) {
    int n = i + 5;

    vector<vector<int>> F(n + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; ++j) {
        F[j][1] = 1;
        F[j][j] = 1;
    }

    for (int j = 3; j <= n; ++j) {
        for (int k = 2; k < j; ++k) {
            F[j][k] = F[j - 1][k - 1] + k * F[j - 1][k];
        }
    }

    vector<int> B(n + 1, 0);
    B[1] = 1;
    for (int j = 2; j <= n; ++j) {
        for (int k = 1; k <= j; ++k) {
            B[j] += F[j][k];
        }
    }

    cout << "Stirling numbers of the second kind:" << endl;
    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= j; ++k) {
            cout << F[j][k] << "\t";
        }
        cout << endl;
    }

    cout << "Bell numbers:" << endl;
    for (int j = 1; j <= n; ++j) {
        cout << B[j] << "\t";
    }
    cout << endl;
}

int main() {
    int n = 8;
    int r = 8;
    int permutations = permutationCount(n, r);
    cout << "Number of placements without repetitions of " << n << " elements by " << r << " = " << permutations << endl;

    int i = 20;
    stirlingAndBell(i);

    return 0;
}
