#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, v;
    cin >> a >> b >> v;
    
    if (v == a) cout << 1 << "\n";
    else {
        double m = (double)(v - a) / (double)(a - b);
        int day = ceil(m) + 1;
        cout << day << "\n";
    }

    

    return 0;
}