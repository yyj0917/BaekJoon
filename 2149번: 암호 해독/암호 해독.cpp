#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string key, password;
    cin >> key >> password;

    int key_len = key.length();
    int password_len = password.length();

    int row_num = password_len / key_len;
    // cout << sort_key << endl;
    // for (int i = 0; i < row_num; i++)
    // {
    //     for (char c : str[i]) {
    //     cout << c << " ";
    //     }
    //     cout << endl;
    // }
    
    // cout << endl;
    vector<vector<char>> result(row_num, vector<char> (key_len));
    // (문자, 원래 열 인덱스)
    vector<pair<char,int>> cols;
    cols.reserve(key_len);
    for (int i = 0; i < key_len; i++) cols.push_back({key[i], i});   
    stable_sort(cols.begin(), cols.end(),
                [](auto &a, auto &b){
                    if (a.first != b.first) return a.first < b.first;
                    return a.second < b.second;
                });
    
    int pos = 0;
    for (int i = 0; i < key_len; i++)
    {
        int col = cols[i].second;
        for (int j = 0; j < row_num; j++)
        {
            result[j][col] = password[pos++];
        }
    }
    
    for (int i = 0; i < row_num; i++)
    {
        for (int j = 0; j < key_len; j++)
        {
            cout << result[i][j];
        }
        
    }
    

    return 0;
}