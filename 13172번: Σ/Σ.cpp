#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int M;
long long ans;

const long long X = 1000000007;

long long solve(long long n, long long b) {
    if (n == 0) return 1; // base case
    if (n == 1) return b % X;

    long long temp = solve(n/2, b);
    long long res = (temp * temp) % X;
    
    if (n % 2 == 1) res = (res * b) % X;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        long long b, a;
        cin >> b >> a;

        int b_rev; // b의 역원 - b^X-2 === b^-1(mod X)

        b_rev = solve(X-2, b);

        // ans = (a * b_rev) mod X
        long long res = (a * b_rev) % X;
        ans += res;
        ans %= X;
    }
    
    cout << ans;

    return 0;
}