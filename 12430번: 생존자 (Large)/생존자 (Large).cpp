#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#define pii pair<int, int>
using namespace std;


bool DP[101005];
// 해당 시간까지 허기를 버틸 수 있는지 없는지
// 처리한 음식의 개수는 사실 상태에 포함되지만, DP식에는 숨김

bool compare(pii A, pii B){
    return A.first+A.second < B.first+B.second;
} // P+S가 작은 순으로 정렬

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        vector<pii> food(N+1); // {P, S}
        for (int i = 1; i <= N; i++)
        {
            cin >> food[i].first >> food[i].second;
        }
        sort(food.begin(), food.end(), compare);
        memset(DP, false, sizeof(DP));
        DP[0] = 1;
        
        for (int i = 1; i <= N; i++) // N개의 음식에 대해 각각 테스트
        {
            for (int j = 101000; j >= 0; j--)
            {
               if(!DP[j]) continue; // 해당 상태에서 전이 불가능
               // 1. 음식을 먹지 않는 경우 -> pass

               // 2. 음식을 먹는 경우
               if (j <= food[i].first) {
                DP[j + food[i].second] = 1;
               }
            }
        }
        for (int i = 101000; i >= 0; i--)
        {
            if (DP[i]) {
                cout << "Case #" << t << ": " << i << endl;
                break;
            }
        }
        
    }
    

    return 0;
}