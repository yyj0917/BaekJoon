#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    
    
    for (int i = 0; i < n; i++)
    {
        string str;
        vector<int> v(26);
        bool check = true;

        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            int num = str[j] - 'a';
            
            if (v[num] == 0) {
                if (j+1 < str.length() 
                && str[j+1] != str[j]) {
                    v[num] = 2;
                } else v[num] = 1;
                
            } else if (v[num] == 1) {
                if (j+1 < str.length() 
                && str[j+1] != str[j]) {
                    v[num] = 2;
                }
            } else {
                check = false;
                break;
            }
        }
        
        if (check) ans++;
    }
    cout << ans << '\n';
    

    return 0;
}