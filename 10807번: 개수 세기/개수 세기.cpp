#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vector(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vector[i];
    }
    int tmp = 0;
    int v;
    cin >> v;
    for (int i = 0; i < N; i++)
    {
        if (vector[i] == v) {
            tmp += 1;
        }
    }
    cout << tmp << "\n";
    
    return 0;
}