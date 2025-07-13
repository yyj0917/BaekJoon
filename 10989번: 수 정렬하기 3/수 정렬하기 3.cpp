#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int cnt_arr[10001] = {0};

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt_arr[x] += 1;
    }
    
    for (int i = 1; i < 10001; i++)
    {
        if (cnt_arr[i] != 0) {
            for (int j = 0; j < cnt_arr[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }
    
    return 0;
}