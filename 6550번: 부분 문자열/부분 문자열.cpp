#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    while (cin >> s >> t)
    {
        int s_idx = 0;
        bool ans = true;
        while (s_idx < s.length())
        {
            char check_s_char = s[s_idx];
            if (t.find(check_s_char) == -1) {
                ans = false;
                break;
            }
            int idx = t.find(check_s_char);
            t = t.substr(idx+1);
            s_idx++;
        }
        cout << (ans ? "Yes" : "No") << "\n";
    }
    

    return 0;
}