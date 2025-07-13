#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int max = 0;

    for (int i = 0; i < N; i++) // N번
    {
        for (int j = i+1; j < N; j++)
        {
            for (int k = j+1; k < N; k++)
            {
                int val = v[i] + v[j] + v[k];
                // 가장 M에 가까운 수 구하기
                if (val <= M) {
                    if (max == 0) {
                        max = val;
                    } else if (max != 0 && max < val) {
                        max = val;
                    }
                }
            }
        }
    }
    cout << max << endl;
    return 0;
    
    
}