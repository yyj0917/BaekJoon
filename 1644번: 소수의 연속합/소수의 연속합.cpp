#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N;
vector<bool> is_prime;

void sieve(int n) {
    // 0과 1은 소수가 아니므로 n까지 포함하기 위해 n+1 크기로 생성
    // 처음에는 모두 소수(true)라고 가정합니다.
    
    is_prime[0] = is_prime[1] = false;

    // n의 제곱근까지만 확인하면 됩니다.
    for (int i = 2; i * i <= n; i++) {
        // i가 소수라면, i의 배수들을 모두 지웁니다.
        if (is_prime[i]) {
            // i*i 미만의 배수들은 이미 이전 단계에서 지워졌으므로 i*i부터 시작
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    is_prime.resize(N+1, true);

    sieve(N); // 소수는 true로 남기기.

    vector<int> prime_num;
    for (int i = 0; i <= N; i++) {
        if (is_prime[i]) prime_num.push_back(i);
    }

    int start = 0, end = 0;
    int sum = 0;
    int ans = 0;
    while (true)
    {
        if (sum >= N) {
            if (sum == N) ans++;
            sum -= prime_num[start];
            start++;
        } else if (end >= prime_num.size()) {
            break;
        } else {
            sum += prime_num[end];
            end++;
        }
    }
    cout << ans;
    
    

    return 0;
}