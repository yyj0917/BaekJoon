#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long var = c - b;
    long long breakpoint;

    if (var > 0) {
        breakpoint = (a / var) + 1;
    } else {
        breakpoint = -1;
    }
    cout << breakpoint << "\n";

    return 0;
}