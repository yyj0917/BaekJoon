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
    vector<int> num;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }

    vector<int> LIS;
    for (int x : num)
    {
        if (LIS.empty() || LIS.back() < x) {
            LIS.push_back(x);
        } else {
            auto it = lower_bound(LIS.begin(), LIS.end(), x);
            *it = x;
        }
    }
    cout << LIS.size();
    

    return 0;
}