#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--) 
    {
        int M;
        cin >> M;
        vector<int> num;
        priority_queue<int, vector<int>, greater<int>> min_heap; // 내림차순
        priority_queue<int> max_heap; // 오름차순
        
        cout << (M+1) / 2 << "\n";
        int cout_cnt = 0;
        for (int i = 1; i <= M; i++)
        {
            int tmp;
            cin >> tmp;
            
            if (max_heap.size() == min_heap.size()) {
                max_heap.push(tmp);
            } else if (max_heap.size() > min_heap.size()) {
                min_heap.push(tmp);
            }
            if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
                int mxht = max_heap.top();
                int mnht = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(mnht);
                min_heap.push(mxht);
            }
            if (i % 2 == 1) {
                cout << max_heap.top() << " ";
                cout_cnt++;
            }
            if (cout_cnt == 10) {
                cout << "\n";
                cout_cnt = 0;
            }
        }
        cout << "\n";
        
    }
    

    return 0;
}