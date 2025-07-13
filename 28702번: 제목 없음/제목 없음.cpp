#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool isInteger(const string& s) {
    try {
        stoi(s);
        return true;
    } catch(...) {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v = {"Fizz", "Buzz", "11"};

    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];
    }
    int output = 0;

    if (v[1] == "Fizz") {
        if (v[2] == "Buzz") {
            output = stoi(v[0]) + 3;
        } else if (v[2] == "FizzBuzz") {
            output = stoi(v[0]) + 3;
        } else {
            output = stoi(v[2]) + 1;
        }
    } else if (v[1] == "Buzz") {
        if (v[2] == "Fizz") {
            output = stoi(v[0]) + 3;
        } else {
            output = stoi(v[2]) + 1;
        }
    } else if (v[1] == "FizzBuzz") {
        if (isInteger(v[2])) {
            output = stoi(v[2]) + 1;
        }
    } else {
        output = stoi(v[1]) + 2;
    }
    if (output % 15 == 0) cout << "FizzBuzz" << "\n";
    else if (output % 5 == 0) cout << "Buzz" << "\n";
    else if (output % 3 == 0) cout << "Fizz" << "\n";
    else cout << output << "\n";

    return 0;
}