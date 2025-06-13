#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v(31);

    for (int i = 1; i < 31; i++)
    {
        int a;
        cin >> a;
        v[a] = a;
    }
    for (int i = 1; i < 31; i++)
    {
        if (v[i] == 0) {
            cout << i << "\n";
        }
    }
    return 0;
    
    
}