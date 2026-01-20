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

    int N;
    cin >> N;
    vector<int> V(N);

    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }

    
    stack<int> st;
    vector<int> ans(N);

    for (int i = N-1; i >= 0; i--)
    {
        while (!st.empty()&&V[st.top()] < V[i])
        {
            ans[st.top()] = i+1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = 0;
        st.pop();
    }
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    

    return 0;
}