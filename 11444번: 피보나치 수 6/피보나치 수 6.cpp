#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<vector<long long>> matrix;

const long long MOD = 1000000007;
long long n;


// 행렬 2x2 곱하기 + 수가 너무 커지지 않게 모듈러 계산
matrix matrix_multiply(matrix &A, matrix &B) {
    matrix C (2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}
// n을 분할정복을 통해 시간복잡도를 log n으로 줄이기
matrix solve(matrix A, long long n) {
    // base case
    if (n == 1) return A;

    // A^(n/2)
    matrix half = solve(A, n/2);

    // A^n = A^(n/2) * A^(n/2)
    matrix result = matrix_multiply(half, half);

    // 만약 n이 홀수라면 base A를 한 번 더 곱해준다
    if (n % 2 == 1) {
        matrix base = {{1, 1}, {1, 0}};
        result = matrix_multiply(result, base);
    }
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    matrix A = {{1, 1}, {1, 0}};

    cout << solve(A, n)[0][1];
    return 0;
}