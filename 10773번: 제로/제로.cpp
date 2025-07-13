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

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x != 0) {
            v.push_back(x);
        } else {
            v.pop_back();
        }
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << sum << "\n";
    
    return 0;
}