#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

long long calc(vector<int> &tree, long long sum[], int h) {
    auto it = upper_bound(tree.begin(), tree.end(), h);
    int idx = it - tree.begin();
    int n = tree.size();

    if (idx >= n) return 0;

    long long leftSum = (idx > 0 ? sum[idx-1] : 0);

    long long cnt = n - idx;
    
    long long result = sum[n-1] - leftSum - cnt * h;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> tree(n);
    long long sum[n];

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());
    for (int i = 0; i < n; i++)
    {
        if (i == 0) sum[i] = tree[i];
        else {
            sum[i] = sum[i-1] + tree[i];
        }
    }
    

    int maxM = 0;

    int r = tree[n-1];
    int l = 0;

    while (l <= r) {

        int mid = (l + r) / 2;

        long long wood = calc(tree, sum, mid);

        if (wood >= m) {
            maxM = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << maxM << '\n';
    

    return 0;
}