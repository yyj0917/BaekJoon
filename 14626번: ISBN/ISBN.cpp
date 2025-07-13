#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(13);

    string str;
    cin >> str;

    int m;
    int idx = 0;
    for (int i = 0; i < 13; i++)
    {
        if (str[i] != '*') {
            int val = str[i] - '0';
            if (i % 2 == 0) {
                v[i] = val;
            } else {
                v[i] = 3 * val;
            }
        } else {
            idx = i;
        }
    }
    int sum = 0;
    for (int i = 0; i < 13; i++)
    {
       sum += v[i];
    }
    for (int i = 0; i < 10; i++)
    {
        if (idx % 2 == 0) {
            if ((sum + i) % 10 == 0) {
                cout << i << "\n";
            }
        } else {
            if ((sum + 3 * i) % 10 == 0) {
                cout << i << "\n";
            }
        }
    }
    
    return 0;
}