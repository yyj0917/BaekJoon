#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int one_max = -1001;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> num(n+1);
    for (int i = 0; i < n; i++)
    {
       cin >> num[i];
       if (num[i] > one_max) one_max = num[i];
    }

    vector<int> max_sum(n+1);
    max_sum[0] = num[0];
    for (int i = 1; i < n; i++)
    {
        max_sum[i] = max(max_sum[i-1] + num[i], num[i]);
        // if ((max_sum[i-1] + num[i]) > one_max) {
        //     max_sum[i] = max_sum[i-1] + num[i];
        // } else max_sum[i] = 0;
    }
    
    int sol = one_max;
    for (int i = 0; i < n; i++)
    {
        if (max_sum[i] == 0) continue;
        sol = max(sol, max_sum[i]);
    }
    cout << sol << '\n';
    

    return 0;
}