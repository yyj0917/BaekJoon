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

    string str;
    while(true) {
        getline(cin, str);
        if (str == ".") break;
        stack<char> st;
        string result = "";
        for (char c : str) {
            if ((c == '(') || (c == '[')) {
                st.push(c);
            }
            else if (c == ')' || c == ']') {
                if (st.empty()) {
                    result = "no";
                    break;
                }
                if (c == ')' && st.top() == '(') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
                else {
                    result = "no";
                    break;
                }
            }
        }
        if (st.empty() && result == "") {
            result = "yes";
        } else {
            result = "no";
        }
        cout << result << "\n";

    }
    return 0;
}