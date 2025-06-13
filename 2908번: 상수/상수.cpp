#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    istringstream iss1(str1);
    istringstream iss2(str2);

    string s1, s2;
    iss1 >> s1;
    iss2 >> s2;
    swap(s1.front(), s1.back());
    swap(s2.front(), s2.back());

    int a = stoi(s1);
    int b = stoi(s2);

    if (a > b) {
        cout << a << "\n";
    } else {
        cout << b << "\n";
    }
    return 0;
}