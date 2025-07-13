#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;


    for (int i = 0; i < N; i++)
    {
        int left_ps = 0, right_ps = 0;
        bool break_iter = false;
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            if (left_ps == 0 && str[j] == ')') {
                cout << "NO" << endl;
                break_iter = true;
                break;
            }
            else {
                if (str[j] == '(') {
                    left_ps++;
                } else {
                    if (left_ps == 0) {
                        cout << "NO" << endl;
                        break_iter = true;
                        break;
                    }
                    else {
                        left_ps--;
                    }
                }
            }
        }
        if (!break_iter) {
            if (left_ps > 0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
    
}