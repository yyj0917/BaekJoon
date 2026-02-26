#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<int> w;
    vector<int> satisfy;


    for (int i = 1; i <= N; i++)
    {
        int v, c, k;
        cin >> v >> c >> k;
        int j = 1;
        while (true)
        {
            if (k >= j) {
                k -= j;
                w.push_back(v*j);
                satisfy.push_back(c*j);
            } else {
                w.push_back(v*k);
                satisfy.push_back(c*k);
                break;
            }
            j *= 2;
        }
        
    }
    
    vector<int> dp(M+1, 0);
    for (int i = 1; i <= w.size(); i++) {
        int weight = w[i-1];
        int s = satisfy[i-1];

        for (int j = M; j >= weight; j--) {
            dp[j] = max(dp[j], dp[j - weight] + s);
        }
    }
    for (int i = M; i >= 0; i--)
    {
        if (dp[i] != 0) {
            cout << dp[i];
            break;
        }
    }
    
    

    return 0;
}