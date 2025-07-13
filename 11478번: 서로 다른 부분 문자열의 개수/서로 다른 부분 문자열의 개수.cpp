#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);

    set<string> set;

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i; j < line.size(); j++)
        {   
            set.insert(line.substr(i, j-i+1));
        }
    }
    cout << set.size() << endl;
    return 0;
}