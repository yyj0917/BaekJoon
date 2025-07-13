#include <iostream>
#include <vector>
#include <string>
using namespace std;

int generator(int n) {
    string str = to_string(n);
    for (int i = 0; i < str.size(); i++)
    {
        n += str[i] - '0';
    }
    return n;
}

int main() {
    vector<int> gen(10000);
    for (int i = 1; i < 10000; i++)
    {
        int val = generator(i);
        gen[val] = val;
    }
    for (int i = 1; i < 10000; i++)
    {
        if (gen[i] == 0) {
            cout << i << endl;
        }
    }
    return 0;
    
}