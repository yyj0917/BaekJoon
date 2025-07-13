#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> minus_v(10000001);
    vector<int> plus_v(10000001);

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0) {
            minus_v[abs(tmp)] += 1;
        } else {
            plus_v[tmp] += 1;
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0) {
            cout << minus_v[abs(tmp)] << " ";
        } else {
            cout << plus_v[tmp] << " ";
        }
    }
    return 0;
}