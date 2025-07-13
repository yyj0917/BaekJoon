#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; i++)
    {
       cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.y == b.y) return a.x < b.x;
        else return a.y < b.y;
    });

    for (int i = 0; i < N; i++)
    {
        cout << points[i].x << " " << points[i].y << "\n";
    }

    return 0;
}