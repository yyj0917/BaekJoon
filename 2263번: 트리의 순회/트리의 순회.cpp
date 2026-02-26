#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<int> inorder(100001);
vector<int> postorder(100001);
vector<int> pos(100001);

void solve(int in_start, int in_end, int post_start, int post_end) {

    if (in_start > in_end) return;
    cout << postorder[post_end] << " ";

    int root_pos = pos[postorder[post_end]];

    int left_subtree_size = root_pos - in_start;

    // 왼쪽 서브트리 영역
    solve(in_start, root_pos-1, post_start, post_start + left_subtree_size-1);

    // 오른쪽 서브트리 영역
    solve(root_pos+1, in_end, post_start + left_subtree_size, post_end - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }

    solve(1, n, 1, n);

    return 0;
}