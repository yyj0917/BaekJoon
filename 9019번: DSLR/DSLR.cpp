#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

bool isBreak = false;

int D(int A) {
    return (2 * A) % 10000;
}
int S(int A) {
    if (A == 0) return 9999;
    else return A - 1;
}
int L(int A) {
    return (A % 1000) * 10 + A / 1000;

}
int R(int A) {
    return (A % 10) * 1000 + A / 10;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int A, B;
        cin >> A >> B;

        
        queue<pair<int, string>> q;
        vector<bool> visited(10000, false);
        q.push({A, ""});
        visited[A] = true;

        while (!q.empty())
        {
            int cur_num = q.front().first;
            string cur_cmd = q.front().second;
            q.pop();

            if (cur_num == B) {
                cout << cur_cmd << endl;
                break;
            }

            int nextNumD = D(cur_num);
            if (!visited[nextNumD]) {
                string cmd = cur_cmd + "D";
                visited[nextNumD] = true;
                q.push({nextNumD, cmd});
            }

            int nextNumS = S(cur_num);
            if (!visited[nextNumS]) {
                string cmd = cur_cmd + "S";
                visited[nextNumS] = true;
                q.push({nextNumS, cmd});
            }

            int nextNumL = L(cur_num);
            if (!visited[nextNumL]) {
                string cmd = cur_cmd + "L";
                visited[nextNumL] = true;
                q.push({nextNumL, cmd});
            }

            int nextNumR = R(cur_num);
            if (!visited[nextNumR]) {
                string cmd = cur_cmd + "R";
                visited[nextNumR] = true;
                q.push({nextNumR, cmd});
            }
        }
        

    }
    

    return 0;
}