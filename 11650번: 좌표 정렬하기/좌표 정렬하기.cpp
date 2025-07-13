#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<point> points(N);

    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    
    sort(points.begin(), points.end(), [](const point &a, const point &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    for (int i = 0; i < N; i++)
    {
        cout << points[i].x << " " << points[i].y << "\n";
    }
    return 0;
}