#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
const string str = "abcdefghijklmnopqrstuvwxyz";

// i칸의 알파벳이 j칸만큼 뒤의 알파벳으로 바꿨을 때의 알파벳
char memo[26][26];

char translate(char c, int num) {
    int idx = c - 'a';
    return memo[idx][num];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i + j >= 26) {
                memo[i][j] = str[i+j-26];
            } else memo[i][j] = str[i+j];
        }
    }

    // input section
    string input_str;
    cin >> input_str;
    int N;
    cin >> N;
    vector<string> s;
    for (int i = 0; i < N; i++) {
        string st;
        cin >> st;
        s.push_back(st);
    }
    

    for (int i = 0; i < 26; i++) // X칸 뒤 암호
    {
        string translate_str;
        for (int j = 0; j < input_str.length(); j++)
        {
           translate_str += translate(input_str[j], i);
        }
        for (int j = 0; j < N; j++)
        {
            if (translate_str.find(s[j]) != -1) {
                cout << translate_str;
                return 0;
            }
        }
        
        
    }
    
    

    return 0;
}