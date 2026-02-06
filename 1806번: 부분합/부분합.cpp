#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, S;

vector<int> num;
vector<int> sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    int max_sum = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
        max_sum += x;
    }
    sum.resize(N);
    sum[0] = num[0];
    // S를 만들지 못할 때 0 출력
    if (max_sum < S) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i-1] + num[i];
    }
    

    int start = 0, end = 0; int min_len = 1e9;
    while (true)
    {
        if (start > end || end >= N) break;
        int check_sum = sum[end] - sum[start] + num[start];
        if (check_sum >= S) {
            min_len = min(min_len, end - start + 1);
            start++;
        } else {
            end++;
        }
    }
    cout << min_len;
    
    


    
    return 0;
}