#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr2[N];

    int idx = 0;
    for (int i = 666; i < 1000000000; i++)
    {
        if (idx >= N) break;
        string str = to_string(i);
        for (int j = 0; j < str.size()-2; j++) {
            if ((str[j] - '0') == 6) {
                if ((str[j+1] - '0') == 6 && (str[j+2] - '0') == 6) {
                    arr2[idx] = i;
                    ++idx;
                    break;
                }
            }
        }
    }
    cout << arr2[N-1] << endl;
    return 0;
}