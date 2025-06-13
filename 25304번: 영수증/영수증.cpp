#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;
    int N;
    cin >> N;

    int val = 0;
    for (int i = 0; i < N; i++)
    {
        int a,b;
        cin >> a >> b;
        val += a * b;
    }
    if (X == val) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    
}