#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int n = 0;
    string str;
    getline(cin, str);

    istringstream iss(str);
    string word;

    while(iss >> word) {
        n += 1;
    }
    cout << n << "\n";

    return 0;
}