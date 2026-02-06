#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
vector<int> A, B;

// max_num = 가장 나중인 수열의 맨 앞 수, max_num_idx는 맨 앞수가 수열의 어디 인덱스인지

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int b;
        cin >> b;
        B.push_back(b);
    }
    

    
    vector<int> last_seq;
    int max_num_idx_A = -1, max_num_idx_B = -1;
    while (true)
    {
        int tmp_idx_A = -1, tmp_idx_B = -1, max_num = -1;
        for (int i = max_num_idx_A+1; i < N; i++) {
            for (int j = max_num_idx_B+1; j < M; j++) {
                if (A[i] == B[j]) {
                    if (A[i] > max_num) {
                        max_num = A[i];
                        tmp_idx_A = i;
                        tmp_idx_B = j;
                        break;
                    }
                }
            }
        }
        if (tmp_idx_A == -1) break; // 같은 수를 발견 못 했다 -> 나중 수열의 최대 크기가 정해졌다.
        // max_num & idx 구하기 긑
        last_seq.push_back(max_num);
        max_num_idx_A = tmp_idx_A;
        max_num_idx_B = tmp_idx_B;
    }
    cout << last_seq.size() << "\n";

    for (int &x : last_seq) {
        cout << x << " ";
    }
    
    return 0;
}