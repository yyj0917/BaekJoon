#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string input;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;

    stack<char> st;
    int ans = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (i < input.length()-1 && input[i] == '(' && input[i+1] == '(')
            st.push('(');
        else if (i < input.length()-1 && input[i] == '(' && input[i+1] == ')') {
            ans += st.size();
            i += 1;
        }
        else if (input[i] == ')') {
            ans += 1;
            st.pop();
        }
    }
    cout << ans;

    return 0;
}