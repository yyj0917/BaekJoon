#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 'W' 시작 체스판
int countW(string wb, int cnt) {
    int result_w = 0;
    for (int i = 0; i < 8; i++)
    {
        if (cnt % 2 == 0) {
            if (i % 2 == 0) { // W로 시작 -> 짝수번째 B->W
                if (wb[i] == 'B') {
                    // wb[i] = 'W';
                    result_w += 1;
                }
            } else { // W로 시작 -> 홀수번째 W->B
                if (wb[i] == 'W') {
                    // wb[i] = 'B';
                    result_w += 1;
                }
            }
        } else {
            if (i % 2 == 0) { // W로 시작 -> 짝수번째 B->W
                if (wb[i] == 'W') {
                    // wb[i] = 'B';
                    result_w += 1;
                }
            } else { // W로 시작 -> 홀수번째 W->B
                if (wb[i] == 'B') {
                    // wb[i] = 'W';
                    result_w += 1;
                }
            }
        }
    }
    return result_w;
}

// 'B' 시작 체스판
int countB(string wb, int cnt) {
    int result_b = 0;
    for (int i = 0; i < 8; i++)
    {
        if (cnt % 2 == 0) {
            if (i % 2 == 0) { // W로 시작 -> 짝수번째 B->W
                if (wb[i] == 'W') {
                    // wb[i] = 'B';
                    result_b += 1;
                }
            } else { // W로 시작 -> 홀수번째 W->B
                if (wb[i] == 'B') {
                    // wb[i] = 'W';
                    result_b += 1;
                }
            }
        } else {
            if (i % 2 == 0) { // W로 시작 -> 짝수번째 B->W
                if (wb[i] == 'B') {
                    // wb[i] = 'W';
                    result_b += 1;
                }
            } else { // W로 시작 -> 홀수번째 W->B
                if (wb[i] == 'W') {
                    // wb[i] = 'B';
                    result_b += 1;
                }
            }
        }
    }
    return result_b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    cin.ignore();

    vector<string> v(N);

    for (int i = 0; i < N; i++)
    {
        getline(cin, v[i]);
    }
    
    
    int min_num = 0;
    for (int i = 0; i < N-7; i++)
    {
        
        for (int j = 0; j < M-7; j++)
        {
            int result_w = 0;
            int result_b = 0;
            for (int k = 0; k < 8; k++)
            {
                string substr = v[i+k].substr(j,  8);
                result_w += countW(substr, k);
                result_b += countB(substr, k);
            }
            if (result_w == 0 || result_b == 0) {
                cout << 0 << endl;
                return 0;
            } else {
                int result = 0;

                if (result_w > result_b) result = result_b;
                else result = result_w;

                if (min_num == 0) {
                    min_num = result;
                } else if (min_num > result) {
                    min_num = result;
                }
            }
        }
    }
    cout << min_num << endl;
    
    
    return 0;
    
    
}