#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int factorial(int M) {
    int result = 1;
    for (int i = 1; i < M+1; i++)
    {
        result *= i;
    }
    return result;
    
}

int main() {
    int N, K;
    cin >> N >> K;

    int val = factorial(N) / (factorial(K) * factorial(N - K));
    cout << val << endl;
    
    return 0;
    
    
}