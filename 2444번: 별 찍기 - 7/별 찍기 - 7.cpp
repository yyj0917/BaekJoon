#include <iostream>
using namespace std;


int main() {
    cout << unitbuf;
    int N;
    cin >> N;

    for (int i = 0; i < N-1; i++)
    {
        for (int k = 1; k <= N+i; k++)
        {
            if (k >= N-i) {
                if (k <= N+i) {
                    cout << '*';
                } else {
                    cout << ' ';
                }
            } else {
                cout << ' ';
            }
        }
        cout << "\n";
    }

    int tmp = 0;
    for (int i = N; i > 0; i--)
    {
        for (int k = 1; k < 2*N-tmp; k++)
        {
            if ((k > N-i) && (k < N+i)) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        tmp += 1;
        cout << "\n";
    }
    return 0;
}