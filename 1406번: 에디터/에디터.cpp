#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
string init_str;
int N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> init_str >> N;

    stack<char> st;
    string result;
    for (int i = 0; i < init_str.length(); i++)
        st.push(init_str[i]);
    
    while (N--)
    {
        char inst, add_c;
        cin >> inst;

        if (inst == 'P') {
            cin >> add_c;
            st.push(add_c);
        }
        else if (inst == 'L' && !st.empty()) {
            int top = st.top();
            result.push_back(top);
            st.pop();
        }
        else if (inst == 'B' && !st.empty()) {
            st.pop();
        }
        else if (inst == 'D' && !result.empty()) {
            st.push(result[result.size()-1]);
            result.pop_back();
        }
    }
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    cout << result;
    

    return 0;
}