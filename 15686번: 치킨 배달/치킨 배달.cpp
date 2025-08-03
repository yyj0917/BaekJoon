#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<pair<int, int>> houses, chicken_houses;
int min_chicken_dist = INT_MAX;

int calculate_distance(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}
int calculation_city_chicken_dist(vector<bool> &selected_check) {
    int city_dist = 0;
    for (auto &house : houses) {
        int min_house_chicken_dist = INT_MAX;
        for (int i = 0; i < chicken_houses.size(); i++)
        {
            if (selected_check[i]) {
                min_house_chicken_dist = min(min_house_chicken_dist, calculate_distance(house.first, house.second, chicken_houses[i].first, chicken_houses[i].second));
            }
        }
        city_dist += min_house_chicken_dist;
    }
    return city_dist;
}

void pick_chicken_houses(int idx, int count, vector<bool> &selected_check) {
    // m개 골랐으면 최소 거리 구하기
    if (count == m) {
        min_chicken_dist = min(min_chicken_dist, calculation_city_chicken_dist(selected_check));
        return;
    }
    if (idx == chicken_houses.size()) {
        return;
    }

    selected_check[idx] = true;
    pick_chicken_houses(idx+1, count+1, selected_check);

    selected_check[idx] = false;
    pick_chicken_houses(idx+1, count, selected_check);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cell;
            cin >> cell;
            if (cell == 2) 
                chicken_houses.push_back({i, j});
            else if (cell == 1)
                houses.push_back({i, j});
        }
    }
    vector<bool> selected_check(chicken_houses.size()+1);
    pick_chicken_houses(0, 0, selected_check);

    cout << min_chicken_dist << '\n';
    return 0;
}