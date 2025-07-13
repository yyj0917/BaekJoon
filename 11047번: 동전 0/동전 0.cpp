#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum;
    cin >> n >> sum;
    
    vector<int> coin(n);

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    int coin_cnt = 0;
    int k = n-1;
    while(sum != 0) {

        if ((sum / coin[k]) != 0) {
            coin_cnt += sum / coin[k];
            sum %= coin[k];
        }
        k--;
    }
    cout << coin_cnt << endl;

    return 0;
}