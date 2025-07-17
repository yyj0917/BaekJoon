#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int n, r, c;

int cnt = 0;
void Z(int row, int col, int size) {

    if (size == 1) {
        cout << cnt << '\n';
        return;
    }

    int half = size / 2;
    // 1사분면
    if (r < row + half && c < col + half) {
        Z(row, col, half);
    } 
    // 2사분면
    else if (r < row + half && col + half <= c) {
        cnt += half * half;
        Z(row, col + half, half);
    }
    // 3사분면
    else if (row + half <= r && c < col + half) {
        cnt += half * half * 2;
        Z(row + half, col, half);
    }
    // 4사분면
    else {
        cnt += half * half * 3;
        Z(row + half, col + half, half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;

    int size = pow(2, n);

    Z(0, 0, size);
    return 0;
}