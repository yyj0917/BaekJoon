#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> str_v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> str_v[i];
    }
    
    sort(str_v.begin(), str_v.end(), [](auto &a, auto &b) {
        if (a.size() == b.size()) {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] != b[i]) return a[i] < b[i];
            }
        }
        return a.size() < b.size();
    });

    for (int i = 0; i < N; i++)
    {
        if (str_v[i] != str_v[i+1]) {
            cout << str_v[i] << endl;
        }
    }

    return 0;
    
}