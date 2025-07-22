#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, b;

int land[500][500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> b;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
        }
    }

    vector<int> answer(257, INT_MAX);
    for (int i = 0; i < 257; i++)
    {
        int fixH = i;
        int remove = 0;
        int add = 0;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (land[j][k] > fixH) {
                    remove += land[j][k] - fixH;
                } else if (land[j][k] < fixH) {
                    add += fixH - land[j][k];
                }
            }
        }
        if (add > remove + b) continue;
        int time = remove * 2 + add;
        answer[i] = time;
    }
    int min_ans = INT_MAX;
    int min_h = -1;
    for (int i = 0; i < 257; i++)
    {
        if (answer[i] <= min_ans) {
            min_ans = answer[i];
            min_h = i;
        }
    }
    cout << min_ans << " " << min_h << endl;
    
    
    
    return 0;
}