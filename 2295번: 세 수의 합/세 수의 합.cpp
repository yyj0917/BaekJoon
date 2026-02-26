#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int N;

vector<int> sum_check;
vector<int> num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = num[i] + num[j];
            sum_check.push_back(sum);
        }
    }
    sort(num.begin(), num.end());    
    sort(sum_check.begin(), sum_check.end());

    for (int i = N-1; i >= 0; i--)
    {
        int check = num[i];
        for (int j = i-1; j >= 0; j--)
        {
            int tmp = check - num[j];
            if (binary_search(sum_check.begin(), sum_check.end(), tmp)) {
                cout << check;
                return 0;
            }
        }
    }
    
    return 0;
}