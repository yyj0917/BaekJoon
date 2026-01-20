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
    
    vector<int> leftSmall(N, -1); // 각 현재 원소 기준 왼쪽으로 작은 수가 무엇인지
    vector<int> rightSmall(N, N); // 각 현재 원소 기준 오른쪽으로 작은 수가 무엇인지
    
    stack<int> st;

    // 왼작수 구하기
    for (int i = N-1; i >= 0; i--)
    {
        while (!st.empty() && V[st.top()] > V[i])
        {
            leftSmall[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    // 오작수 구하기
    for (int i = 0; i < N; i++)
    {
        while (!st.empty() && V[st.top()] > V[i])
        {
            rightSmall[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        int w = rightSmall[i] - leftSmall[i] - 1;
        int h = V[i];
        ans = max(ans, w * h);
    }
    cout << ans << "\n";

    return 0;
}