#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>  // printf/scanf

using namespace std;

int main() {
    int N, M;
    

    cin >> N;
    vector<int> vn(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vn[i];
    }
    sort(vn.begin(), vn.end());

    cin >> M;
    vector<int> vm(M);
    for (int i = 0; i < M; i++)
    {
        cin >> vm[i];
    }

    for (int i = 0; i < M; i++)
    {

        if (binary_search(vn.begin(), vn.end(), vm[i])) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}