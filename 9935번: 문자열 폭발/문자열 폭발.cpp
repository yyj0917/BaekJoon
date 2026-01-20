#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    string str, boom_str;
    cin >> str >> boom_str;

    string result = "";
    for (char c : str) {
        result += c;
        if (result.length() >= boom_str.length()) {
            if (result.substr(result.length() - boom_str.length()) == boom_str) {
                result.erase(result.length() - boom_str.length());
            }
        }
    }
    if (result.empty()) cout << "FRULA" << "\n";
    else cout << result << "\n";
    
    
    

    return 0;
}