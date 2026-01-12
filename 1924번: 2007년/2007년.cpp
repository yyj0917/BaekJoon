#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int diff[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        sum += diff[i];
    }
    sum += y - 1;
    int ans = sum % 7;

    cout << day[ans] << endl;
    



    return 0;
}