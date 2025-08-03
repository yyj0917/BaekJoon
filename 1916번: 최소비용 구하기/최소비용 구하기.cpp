#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;

struct City {
    int end, weight;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<City> bus(n+1);
    vector<int> dist(n+1, -1);

    for (int i = 1; i <= m; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        bus[start] = {end, weight};
    }
    int start_city, end_city;
    cin >> start_city >> end_city;
    queue<int> q;
    dist[start_city] = 0;
    q.push(start_city);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (City city : bus) {
            if (dist[city.end] == -1) {
                
            }
        }
    }
    

    


    return 0;
}