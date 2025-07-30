#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n;


void preorder(int cur, vector<vector<char>> &tree, vector<bool> &visited) {
    visited[cur] = true;
    cout << char(cur + 'A');

    for (char next : tree[cur]) { // 0번째 - 왼쪽자식, 1번째 - 오른쪽 자식
        if (next != '.' && !visited[next - 'A']) {
            preorder(next - 'A', tree, visited);
        }
    }
}
void inorder(int cur, vector<vector<char>> &tree) {
    if (tree[cur][0] != '.') {
        inorder(tree[cur][0] - 'A', tree);
    }

    cout << char(cur + 'A');

    if (tree[cur][1] != '.') {
        inorder(tree[cur][1] - 'A', tree);
    }
}
void postorder(int cur, vector<vector<char>> &tree) {
    if (tree[cur][0] != '.') {
        postorder(tree[cur][0] - 'A', tree);
    }

    if (tree[cur][1] != '.') {
        postorder(tree[cur][1] - 'A', tree);
    }
    cout << char(cur + 'A');

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<vector<char>> tree(26);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        char parent, child;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0) {
                cin >> parent;
            } else {
                cin >> child;
                tree[parent - 'A'].push_back(child);
            }
        }
    }
    preorder(0, tree, visited);
    cout << endl;
    inorder(0, tree);
    cout << endl;
    postorder(0, tree);
    

    return 0;
}