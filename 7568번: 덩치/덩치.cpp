#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[N][3];

    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j) {
                if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
                    arr[i][2] += 1;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr[i][2] + 1 << " ";
    }
    
    
    return 0;
}