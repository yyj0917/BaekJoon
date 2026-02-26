#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    unordered_set<int> card;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        card.insert(a);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int target;
        cin >> target;
        if (card.count(target)) cout << 1;
        else cout << 0;
        cout << " ";
    }


    return 0;
}