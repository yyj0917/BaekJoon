#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int t;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int calcNum;
        cin >> calcNum;
        multiset<long long> ms;
        while (calcNum--)
        {   
            char inst;
            long long prio;
            cin >> inst >> prio;
            
            if (inst == 'I') ms.insert(prio);
            else {
                if (ms.empty()) continue;
                if (prio == -1) {
                    ms.erase(ms.begin());
                } else {
                    ms.erase(prev(ms.end()));
                }
            }
        }
        if (ms.empty()) cout << "EMPTY" << '\n';
        else {
            int begin = *ms.begin();
            int end = *prev(ms.end());
            cout << end << ' ' << begin << '\n';
        }
        
        
    }
    

    return 0;
}