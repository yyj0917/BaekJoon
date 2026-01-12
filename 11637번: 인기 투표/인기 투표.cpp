#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        int winner = 0;
        cin >> n;
        vector<int> candid(n + 1);
        int all_vote = 0;
        int max_vote = -1;
        int max_vote_candid = 0;
        int same_max_vote = 0;

        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;
            candid[j] = num;
            all_vote += num;
            if (max_vote <= num) {
                max_vote = num;
                max_vote_candid = j;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (candid[j] == max_vote) same_max_vote += 1;
        }
        
        if (same_max_vote > 1 ) {
            cout << "no winner" << '\n';
            continue;
        }
        if (max_vote > all_vote/2) {
            cout << "majority winner " << max_vote_candid << '\n';
        } else {
            cout << "minority winner " << max_vote_candid << '\n';
        }
    }
    

    return 0;
}