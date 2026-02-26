#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> mnh;
    priority_queue<int> mxh;

    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        
        if (mxh.size() == mnh.size()) {
            mxh.push(num);
        } else if (mxh.size() > mnh.size()) {
            mnh.push(num);
        }

        // 항상 최대 힙 root <= 최소 힙 root를 유지하기 위한 swap
        if (!mxh.empty() && !mnh.empty() && mxh.top() > mnh.top()) {
            int a = mxh.top();
            int b = mnh.top();
            mxh.pop(); mnh.pop();
            mxh.push(b); mnh.push(a);
        }

        cout << mxh.top() << "\n";
    }
    

    return 0;
}