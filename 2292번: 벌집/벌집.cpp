#include <iostream>
using namespace std;

int main() {
    long long n;
    long long val = 1;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    for (long long i = 1; i < 1000000000; i++) {
        if (val < n && n < val + 6 * i+1) {
            cout << i + 1 << "\n";
            break;
        }
        val += 6 * i;
    }
    return 0;
}
