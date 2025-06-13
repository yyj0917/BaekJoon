#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    string s;
    getline(cin, s);

    istringstream iss(s);
    vector<int> v;
    int x;
    while(iss >> x) {
        v.push_back(x);
    }

    int T, P;
    cin >> T >> P;

    int return_T = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] != 0) {
            if (v[i] < T+1) {
                return_T += 1;
            } else {
                if (v[i] % T == 0) {
                    return_T += (v[i]/T);
                } else {
                    return_T += (v[i]/T)+1;
                }
            }
        }
    }
    cout << return_T << "\n";
    cout << (N / P) << ' ' << (N % P) << "\n";

    return 0;

}