#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int n, m;
map<int, bool> truthy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    int truthy_len;
    cin >> truthy_len;
    if (truthy_len == 0) {
        cout << m << '\n';
        return 0;
    }
    for (int i = 0; i < truthy_len; i++)
    {
        int x;
        cin >> x;
        truthy[x] = true;
    }

    vector<vector<int>> parties;
    // vector<vector<int>> no_party;
    while (m--)
    {
        int len;
        cin >> len;
        vector<int> arr;
        for (int i = 0; i < len; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        parties.push_back(arr);
    }

    bool changed = true;
    while (changed)
    {
        changed = false;
        for (const auto &party: parties) {
            bool has_truthy = false;
            for (int person : party) {
                if (truthy[person]) {
                    has_truthy = true;
                    break;
                }
            }
            // 이게 전염로직 => 전염이 된다는 건 바뀔 게 필요하다.
            // truthy가 있는 파티인데 다른 파티원들도 다 전염이 안 되었으면 changed는 true로 계속 반복
            if (has_truthy) {
                for (int person : party) {
                    if (!truthy[person]) {
                        truthy[person] = true;
                        changed = true;
                    }
                }
            }
        }
    }
    int ans = parties.size();
      for (const auto &comp : parties) {
          for (int i = 0; i < comp.size(); i++)
          {
              if (truthy[comp[i]]) {
                  ans--;
                  break;
              };
          }
      }
      cout << ans << '\n';

    return 0;
}