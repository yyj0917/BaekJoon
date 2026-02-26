#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int k;

vector<int> result;
void solve(vector<int>& arr, vector<bool>& checked, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (!checked[i]) {
            if (result.empty() || result.back() < arr[i]) {
                result.push_back(arr[i]);
                checked[i] = true;
                solve(arr, checked, cnt+1);
                result.pop_back();
                checked[i] = false;
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> k;
        if (k == 0) break;
        result.clear();
        vector<int> arr(k);
        for (int i = 0; i < k; i++) cin >> arr[i];

        vector<bool> checked(k, false);
        solve(arr, checked, 0);
        cout << "\n";
    }
    

    return 0;
}