#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int white = 0, blue = 0;
vector<vector<int>> paper;
bool is_same_color(int row, int col, int size) {
    int color = paper[row][col];

    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if (paper[i][j] != color) return false;
        }
    }
    return true;
}

void divide_conquer(int row, int col, int size) {

    int half = size / 2;
    if (is_same_color(row, col, size)) {
        if (paper[row][col] == 0) {
            white++;
        } else blue++;
        return;
    }
    
    divide_conquer(row, col, half);
    divide_conquer(row + half, col, half);
    divide_conquer(row, col + half, half);
    divide_conquer(row + half, col + half, half);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // y, x
    paper.resize(n, vector<int> (n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> paper[i][j];
        }
    }

    divide_conquer(0, 0, n);
    
    cout << white << '\n' << blue << '\n';

    return 0;
}