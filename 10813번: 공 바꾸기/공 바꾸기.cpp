#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        v[i] = i+1;
    }
    for (int i = 0; i < M; i++)
    {
       int a, b;
       cin >> a >> b;

       int tmp = v[a-1];
       v[a-1] = v[b-1];
       v[b-1] = tmp;
    }
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}