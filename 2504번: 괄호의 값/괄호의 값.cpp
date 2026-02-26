#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    bool isChecked = true;
    int len = input.length();
    stack<char> st;
    int ans = 0, tmp = 1;
    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        char before_c = input[i-1];

        if (c == '(') {
            tmp *= 2;
            st.push(c);
        }
        else if (c == '[') {
            tmp *= 3;
            st.push(c);
        }
        else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }
            if (before_c == '(') {
                ans += tmp;
            }
            tmp /= 2;
            st.pop();
        }
        else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }
            if (before_c == '[') {
                ans += tmp;
            }
            tmp /= 3;
            st.pop();
        }
    }
    if (!st.empty()) ans = 0;
    cout << ans;
    

    return 0;
}