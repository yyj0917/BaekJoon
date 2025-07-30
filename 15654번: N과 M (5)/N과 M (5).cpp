#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
int n , m;

void sol(vector<bool> &visited, int depth, vector<int> &arr, vector<int> &current) {
    if (depth == m) {
        for (int i = 0; i < current.size(); i++)
        {
            cout << current[i];
            if (i != current.size()-1) cout << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) {
            current.push_back(arr[i]);
            visited[i] = true;
            sol(visited, depth+1, arr, current);
            current.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int> current;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        current.push_back(arr[i]);
        visited[i] = true;
        sol(visited, 1, arr, current);
        current.pop_back();
        visited[i] = false;
    }
    

    return 0;
}