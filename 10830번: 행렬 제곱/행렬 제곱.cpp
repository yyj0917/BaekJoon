#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
typedef vector<vector<long long>> matrix;

int N;
long long B;

matrix multiply(matrix &A, matrix &B) {
    matrix tmp(N, vector<long long> (N));
    for (int a = 0; a < N; a++) // result row
    {
        for (int b = 0; b < N; b++) // result col
        {
            for (int i = 0; i < N; i++)
            {
                tmp[a][b] += A[a][i] * B[i][b];
            }
            tmp[a][b] %= 1000;
        }
    }
    return tmp;
}
matrix solve(matrix A, long long exp) {
    if (exp == 1) return A;

    matrix half = solve(A, exp / 2);
    matrix result = multiply(half, half);

    if (exp % 2 == 1) {
        result = multiply(result, A);
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;

    matrix m(N, vector<long long> (N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> m[i][j];
            m[i][j] %= 1000;
        }
    }

    matrix result = solve(m, B);

    for (int i = 0; i < N; i++) // row
    {
        for (int j = 0; j < N; j++) // col
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    
    return 0;
}