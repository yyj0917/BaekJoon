#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> V;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        V.push_back(a);
    }

    stack<int> st;
    vector<int> ans(N);

    for (int i = 0; i < N; i++)
    {
        while (!st.empty() && V[st.top()] < V[i])
        {
            ans[st.top()] = V[i];
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    
    
    
    
    

    return 0;
}