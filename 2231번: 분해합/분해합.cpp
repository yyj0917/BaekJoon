#include <iostream>
#include <string>
using namespace std;

bool generatorNum(int M, int N) {
    string str = to_string(M);
    for (int i = 0; i < str.size(); i++)
    {   
        char c = str[i];
        M += c - '0';
    }
    if (M == N) {
        return true;
    } else {
        return false;
    }
    

}

int main() {
    int N;
    int generator = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        if (generatorNum(i, N)) {
            if (generator == 0) {
                generator = i;
            } else if (generator != 0 && generator >= i) {
                generator = i;
            }
        }
    }
    cout << generator << endl;
    return 0;
    
}