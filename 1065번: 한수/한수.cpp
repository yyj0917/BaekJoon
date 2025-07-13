#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

bool sequence_check(int X) {
    string str_x = to_string(X);
    int arr[str_x.size()];
    for (int i = 0; i < str_x.size(); i++)
    {
        arr[i] = str_x[i] - '0';
    }
    int n = arr[0] - arr[1];
    if (n > 0) {
        for (int i = 1; i < str_x.size()-1; i++)
        {
            if (arr[i] - arr[i+1] != n) {
                return false;
            }
        }
    } else {
        n = arr[1] - arr[0];
        for (int i = 1; i < str_x.size()-1; i++)
        {
            if (arr[i+1] - arr[i] != n) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    int result = 0;

    if (N < 100) {
        cout << N << endl;
    } else {
        for (int i = 100; i < N+1; i++)
        {
            if (sequence_check(i)) ++result;
        }
        cout << result+99 << endl;
    }
    return 0;

}