#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

struct member {
    int age, idx;
    string name;
};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N;
    cin >> N;
    cin.ignore();

    member members[N];
    for (int i = 0; i < N; i++)
    {
        cin >> members[i].age >> members[i].name;
        members[i].idx = i;
    }
    sort(members, members + N, [](const member &a, const member &b) {
        if (a.age == b.age) return a.idx < b.idx;
        else return a.age < b.age;
    });
    
    for (int i = 0; i < N; i++)
    {
        cout << members[i].age << " " << members[i].name << endl;
    }
    
    
    return 0;
}