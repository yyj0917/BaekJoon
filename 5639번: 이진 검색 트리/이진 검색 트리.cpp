#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

vector<int> tree;


void solve(int start, int end) {
    if (start > end) return; // 범위를 벗어나는 기저 사례

    int root = tree[start]; // 전위 순회의 첫 결과는 root
    int k = start + 1; // k = root보다 큰 키값이자 경계선 index

    while (k <= end && tree[k] < root)
    {
        k++; // 경계선이자 오른쪽 서브트리의 루트인 k를 찾기 위함
    }
    solve(start+1, k-1); // 왼쪽 재귀
    solve(k, end); // 오른쪽 재귀

    cout << root << "\n"; // 마지막에 루트 출력
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n)
    {
       tree.push_back(n);
    }

    int len = tree.size();

    solve(0, len-1);
    

    return 0;
}