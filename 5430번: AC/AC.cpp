#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

bool isNum(char c) {
    if (c == '[' || c == ',' || c == ']') {
        return false;
    } 
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string ac;
        int len;
        string arr;
        deque<int> dq;
        bool reverse = false;
        cin >> ac >> len >> arr;
        // queue에 숫자만 넣기
        string num = "";
        for (int k = 0; k < arr.size(); k++)
        {
            if (isNum(arr[k])) {
                num += arr[k];
            } else if (!num.empty()) {
                dq.push_back(stoi(num));
                num = "";
            }
        }

        bool isError = false;
        for (char c : ac)
        {
            if (c == 'R') {
                reverse = !reverse;
            } else {
                if (dq.empty()) {
                    cout << "error" << '\n';
                    isError = true;
                    break;
                } else {
                    if (reverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if (!isError) {
            cout << '[';
            int size = dq.size();
            if (reverse) {
                for (int i = 0; i < size; i++)
                {
                    cout << dq.back();
                    dq.pop_back();
                    if (i != size-1) {
                        cout << ',';
                    }
                }
            } else {
                for (int i = 0; i < size; i++)
                {
                    cout << dq.front();
                    dq.pop_front();
                    if (i != size-1) {
                        cout << ',';
                    }
                }
            }
            cout << ']' << '\n';
        }
    }
    

    return 0;
}