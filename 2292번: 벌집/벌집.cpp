#include <iostream>
using namespace std;

int main() {
    long long n;
    int result = 1;
    int var = 1;
    cin >> n;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    for (long long i = 0; i < 1000000000; 2*i-1) {
        var = 1 + 6 * i;
        i++;
        if (var < n && n <= (6 * (2*i -1) + 1)) {
            cout << result+1 << "\n";
            return 0;
        }

        result++;
    }
    return 0;
}
