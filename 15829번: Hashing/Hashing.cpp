#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string str;
    cin >> str;

    long long M = 1234567891;
    long long output = 0;
    long long r = 1;
    for (int i = 0; i < n; i++)
    {
       int tmp = str[i] - 'a' + 1;
       output = (output + (tmp * r)) % M;
       r = (r * 31) % M;
    }
    cout << output << "\n";
    

    return 0;
}