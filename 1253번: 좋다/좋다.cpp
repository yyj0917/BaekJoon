#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int ans = 0;
    cin >> n;

    vector<long long> num(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    for (int target_idx = 0; target_idx < n; target_idx++)
    {

        int left = 0;
        int right = n-1;
        while (left < right)
        {
            if (num[left] + num[right] == num[target_idx]) {
                if (left == target_idx) left++;
                else if (right == target_idx) right--;
                else {
                    ans++;
                    break;
                }
            }
            else if (num[left] + num[right] < num[target_idx]) left++;
            else right--;
        }
        
    }
    cout << ans << endl;


    return 0;
}