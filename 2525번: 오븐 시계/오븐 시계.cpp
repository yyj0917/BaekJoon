#include <iostream>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;

    int end_m;
    cin >> end_m;

    int return_h = 0, return_m = 0;
    
    if ( m + end_m > 59) {
        int tmp = (m + end_m) / 60; // 더해지는 시간

        if ((m + end_m) % 60 != 0) {
            return_m = (m + end_m)%60;
            return_h = tmp;
        } else {
            return_m = 0;
            return_h = tmp;
        }

        if (h + return_h > 23) {
            return_h = (h + return_h)%24;
        } else {
            return_h += h;
        }
    } else {
        return_h = h;
        return_m = m + end_m;
    }
    cout << return_h << " " << return_m << "\n";
    return 0;
}