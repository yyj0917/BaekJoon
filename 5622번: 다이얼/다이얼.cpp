#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> v = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ", ""};

    string s;

    // return value
    int val = 0;

    cin >> s;

    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            for (char c : v[j]) {
                if (c == s[i]) {
                    val += (j + 1);
                }
            }
        }
    }
    cout << val << "\n";
    return 0;
}