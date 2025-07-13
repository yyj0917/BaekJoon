#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int s = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> st;
    vector<char> v(2*n+2);
    int v_idx = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (true)
        {
            if (s > n+1) break;
            if (st.empty()) {
                st.push(s);
                s++;
                v[v_idx] = '+';
                v_idx++;
            } else {
                if (st.top() == x) {
                    st.pop();
                    v[v_idx] = '-';
                    v_idx++;
                    break;
                } else {
                    st.push(s);
                    s++;
                    v[v_idx] = '+';
                    v_idx++;
                }
            }
        }
    }
    if (st.empty()) {
        for (int i = 0; i < v_idx; i++)
        {
            cout << v[i] << "\n";
        }
    }
    else {
        cout << "NO" << "\n";
    }

    return 0;
}