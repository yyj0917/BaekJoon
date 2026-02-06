#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int N;

vector<int> numbers;
int scores[1000006];
int cards[1000006];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;

        numbers.push_back(tmp); // 각 플레이어가 가지고 있는 카드 넘버
        cards[tmp] = 1; // 해당 카드를 누가 가지고 있는지
    }
    
    for (int i = 0; i < N; i++) {
        // 플레이어의 모든 카드 배수를 탐색
        for (int j = 2*numbers[i]; j < 1000001; j += numbers[i]) {
            if (cards[j] == 1) // 플레이어의 카드 배수가 있다는 의미 -> 플레이어가 이김
            {
                scores[numbers[i]]++; // 플레이어 카드 윈
                scores[j]--; // 배수는 -1
            }            
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << scores[numbers[i]] << " ";
    }
    

    return 0;
}