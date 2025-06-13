#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a == b) && (b == c)) { // 같은 눈 3개
        cout << 10000 + a * 1000 << "\n";
    } else if ((a == b) || (a == c) || (b == c)) { // 같은 눈 2개
        if (a == b) {
            cout << 1000 + a * 100 << "\n";
        } else if (b == c) {
            cout << 1000 + b * 100 << "\n";
        } else if (a == c) {
            cout << 1000 + a * 100 << "\n";
        }
    } else { // 모두 다른 눈
        int max = a;
        if (a < b) {
            if (b < c) {
                max = c;
            } else {
                max = b;
            }
            
        } else {
            if (a < c) {
                max = c;
            }
        }
        cout << max * 100 << "\n";
    }
    return 0;
}