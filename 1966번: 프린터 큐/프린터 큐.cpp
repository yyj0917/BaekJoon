#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

struct doc {
    int prio;
    bool target;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N; // 문서의 개수
        int target_idx;
        cin >> N >> target_idx;

        int target_prio = 0;
        deque<int> dq;

        for (int i = 0; i < N; i++)
        {
            int prio;
            cin >> prio;
            if (i == target_idx) target_prio = prio;
            dq.push_back(prio);
        }
        
        int order = 1;
        while (!dq.empty())
        {   
            int max_prio = 0;
            for (auto& a: dq)
            {
                max_prio = max(max_prio, a);
            }
            
            if (pq.top() == target_prio) {
                cout << order << "\n";
                break;
            } else {
                pq.pop();
                order++;
            }
        }
        
        

        // for (int i = 0; i < N; i++)
        // {
        //     int prio;
        //     cin >> prio;
        //     bool target = false;
        //     if (i == target_idx) target = true;
        //     doc_v.push_back({prio, target});
        // }
        
        // int order = 1;
        // while(doc_v.size() != 0) {
        //     int max_prio = 0;
        //     for (auto& p: doc_v)
        //     {
        //        max_prio = max(max_prio, p.prio);
        //     }
            
        //     if (doc_v[0].prio < max_prio) {
        //         bool target = false;
        //         if (doc_v[0].target == true) target = true;
        //         doc_v.push_back({doc_v[0].prio, target}); // 뒤에 넣고
        //         doc_v.erase(doc_v.begin()); // 앞에 거 빼고
        //     } else {
        //         if (doc_v[0].target == 1) {
        //             cout << order << "\n";
        //             break;
        //         } else {
        //             doc_v.erase(doc_v.begin());
        //             order++;
        //         }
        //     }
        // }


    }
    

    return 0;
}