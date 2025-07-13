#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    double sum = 0;

    // 0~4000 & 4001~8000
    vector<int> v(8002);

    vector<int> v_mid(n);
    vector<int> v_freq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        // sum calc
        sum += x;

        // middle val
        v_mid[i] = x;

        if (x >=0) {
            v[x]++;
            
        } else {
            v[abs(x)+4000]++;
        }
    }

    int idx = 0;
    int max_freq = 0;
    // max_freq counting
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > max_freq) {
            max_freq = v[i];
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
       if (v[i] == max_freq) {
        if (i > 4000) {
            int tmp = i;
            tmp -= 4000;
            tmp -= 2*tmp;
            v_freq.push_back(tmp);
        } else {
            v_freq.push_back(i);
        }
        idx++;
       }
    }
    
    sort(v_mid.begin(), v_mid.end());
    sort(v_freq.begin(), v_freq.end());

    auto avg = round(sum / n);
    if (avg == 0) avg = 0;
    cout << avg << "\n";
    

    cout << v_mid[(n-1)/2] << "\n";
    

    if (v_freq.size() > 1) {
        cout << v_freq[1] << "\n";
    } else {
        cout << v_freq[0] << "\n";
    }

    cout << v_mid[n-1] - v_mid[0] << "\n";
    

    return 0;
}