#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        // 전체 갯수
        int n;
        cin >> n;
        // 중복 의상 종류
        int k = 0;
        unordered_map<string, int> um;
        for (int i = 0; i < n; i++)
        {
            string str1, str2;
            cin >> str1 >> str2;
            um[str2]++;
        }

        // 의상 종류별 의상 수 (중복o)
        int closet_val = um.size();
        vector<int> num_v(closet_val);
        for (auto &kv : um) {
            num_v.push_back(kv.second);
        }

        // 각 그룹에서 1. 고르기, 2. 고르지 않기로 나누기
        // 각 경우의 수를 더하고 그룹별 경우의 수를 곱한 뒤 공집합 제거.
        int result = 1;
        for (int i = 0; i < num_v.size(); i++)
        {
            result *= (num_v[i] + 1);
        }
        cout << result - 1 << "\n";
        
    }
    

    return 0;
}