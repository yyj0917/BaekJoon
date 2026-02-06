#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int priority(char c) {
    int a;
    switch (c)
    {
    case '*':
        a = 2;
        break;
    case '/':
        a = 2;
        break;
    case '+':
        a = 1;
        break;
    case '-':
        a = 1;
        break;
    case '(':
        a = 0;
        break;
    case ')':
        a = -1;
        break;
    default:
        a = -2;
        break;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    stack<char> s;

    for (char c : str) {
        if (priority(c) == -2) {
            cout << c;
        }
        else if (priority(c) == 0) {
            s.push(c);
        } 
        else if (priority(c) == -1) {
            while (s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if (priority(c) > 0) {            
            // 스택이 비어있지 않고, 내 머리(top)에 있는 놈이 나보다 우선순위가 높거나 같으면
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                cout << s.top();
                s.pop();
            }
            // 나보다 낮은 놈들만 남았거나 스택이 비었으면 내가 들어감
            s.push(c);
        }
    } 
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}