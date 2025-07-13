#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    if (N < 5) cout << 0 << "\n";
    else if (N >= 5 && N < 25) cout << N/5 << "\n";
    else if (N >= 25 && N < 125) {
        int tmp = 0;
        tmp += N/5;
        tmp += (N / 25);
        cout << tmp << "\n";
    } else {
        int tmp = 0;
        tmp += N/5;
        tmp += (N / 25);
        tmp += (N / 125);
        cout << tmp << "\n";
    }
    
    return 0;
}