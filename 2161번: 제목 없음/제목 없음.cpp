#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> dq;

    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    while (dq.size() != 1)
    {
        cout << dq.front() << " ";
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    cout << dq.front() << "\n";
    
    
    

    return 0;
}