#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    string number;

    for (char c : expr) {
        if (c == '-' || c == '+') {
            if (!number.empty()) {
                tokens.push_back(number);
                number.clear();
            }
            tokens.push_back(string(1, c));
        }
        else {
            number += c;
        }
    }
    if (!number.empty()) tokens.push_back(number);
    
    return tokens;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);

    vector<string> reg;
    reg = tokenize(line);

    int prev_minus = 0; // minus 이전의 합;
    int next_minus = 0; // minus 이후의 합;
    bool isMinus = false;
    for (auto a : reg) {
        if (a == "-" || a == "+") {
            if (a == "-") isMinus = true;
        } else {
            if (isMinus) {
                next_minus += stoi(a);
            } else {
                prev_minus += stoi(a);
            }
        }
    }
    cout << prev_minus - next_minus << '\n';

    return 0;
}
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string line;
//     getline(cin, line);

//     vector<string> tokens = tokenize(line);

//     int result = 0;
//     bool subtracting = false;

//     for (size_t i = 0; i < tokens.size(); ++i) {
//         const string& token = tokens[i];

//         if (token == "-") {
//             subtracting = true;
//         } else if (token == "+") {
//             continue; // 그냥 넘어감
//         } else {
//             int num = stoi(token);
//             if (subtracting) result -= num;
//             else result += num;
//         }
//     }

//     cout << result << '\n';
//     return 0;
// }
