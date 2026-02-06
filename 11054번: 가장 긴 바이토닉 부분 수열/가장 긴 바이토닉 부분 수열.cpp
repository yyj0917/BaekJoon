#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    vector<int> inc(N+1, 1), dec(N+1, 1);
    
    int max_len = -1;
    for (int i = 0; i < N; i++)
    {
        // i번째 수를 끝으로 하는 가장 긴 증가하는 부분 수열
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i]) inc[i] = max(inc[i], inc[j]+1);
        }
    }
    for (int i = N-1; i >= 0; i--)
    {
        // i번째 수를 시작으로 하는 가장 긴 감소하는 부분 수열
        for (int j = N-1; j > i; j--)
        {
            if (A[j] < A[i]) dec[i] = max(dec[i], dec[j]+1);
        }
    }
    for (int i = 0; i < N; i++)
    {
        max_len = max(max_len, inc[i]+dec[i]-1);
    }
    
    cout << max_len;
    


    return 0;
}