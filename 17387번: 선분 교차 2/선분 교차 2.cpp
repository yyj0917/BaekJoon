#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#define pll pair<long, long>
using namespace std;

int ccw(pair<long long, long long>p1, pair<long long, long long>p2, pair<long long, long long>p3) {
    long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
}

bool intersect(pair<pll, pll> L1, pair<pll, pll> L2) {
    pll p1 = L1.first;
    pll p2 = L1.second;
    pll p3 = L2.first;
    pll p4 = L2.second;

    if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4) return true;


    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // L1 기준
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // L2 기준

    // 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // 포개어져있는지 확인
    }
    return p1p2 <= 0 && p3p4 <= 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pair<pll, pll> L1;
    pair<pll, pll> L2;

    cin >> L1.first.first >> L1.first.second >> L1.second.first >> L1.second.second;
    cin >> L2.first.first >> L2.first.second >> L2.second.first >> L2.second.second;

    if (intersect(L1, L2)) cout << 1;
    else cout << 0;
    return 0;
}