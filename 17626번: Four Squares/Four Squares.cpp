#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool isSq(int n) {
    int root = static_cast<int>(sqrt(n) + 0.5);
    return root * root == n;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    if (isSq(n)) {
        cout << 1 << '\n';
        return 0;
    }


    for (int i = 1; i * i <= n; i++)
    {
        if (isSq(n - i * i)) {
            cout << 2 << '\n';
            return 0;
        }
    }
    for (int i = 1; i * i <= n; i++)
    {
        for (int j = 1; j * j <= n - i*i; j++)
        {
            if (isSq(n - i*i - j*j)) {
                cout << 3 << '\n';
                return 0;
            }
        }
    }
    cout << 4 << '\n';
    

    return 0;
}