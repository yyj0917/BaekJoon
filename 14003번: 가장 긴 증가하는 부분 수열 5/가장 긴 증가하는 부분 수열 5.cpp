#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<int> A;
    vector<int> input;
    vector<int> pos;

    int pos_idx = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        input.push_back(a);
        if (A.empty() || A.back() < a) {
            A.push_back(a);
            pos.push_back(A.size()-1);
        } else {
            auto it = lower_bound(A.begin(), A.end(), a);
            *it = a;
            int idx = it-A.begin();
            pos.push_back(idx);
        }
    }
    cout << A.size() << endl;

    vector<int> result;
    int target = A.size() - 1;
    for (int i = N-1; i >= 0; i--) {
        if (pos[i] == target) {
            result.push_back(input[i]);
            target--;
        }
    }
    
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}