#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

vector<int> preorder;
vector<int> inorder;


void solve(int pre_start, int pre_end, int in_start, int in_end) {
    if (in_start > in_end) return;

    int rootValue = preorder[pre_start];
    int idx = 0;
    while (true)
    {
        if (idx <= in_end && rootValue == inorder[idx]) break;
        idx++;
    }
    int leftSize = idx - in_start;
    solve(pre_start+1, pre_start + leftSize, in_start, idx-1); // left recur
    solve(pre_start + leftSize + 1, pre_end, idx + 1, in_end);

    cout << rootValue << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            preorder.push_back(k);
        }
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            inorder.push_back(k);
        }
        solve(0, n-1, 0, n-1);
        cout << "\n";
        preorder.clear();
        inorder.clear();


    }
    

    return 0;
}