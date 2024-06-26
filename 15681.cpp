#include<iostream>
#include<vector>

using namespace std;


void dfs(int r, int prev, vector<vector<int>>& tree, vector<int>& arr) {

    for (int i = 0; i < tree[r].size(); i++) {
        int next=tree[r][i];
        if (next == prev) {
            continue;
        }
        dfs(next, r,tree, arr);
        arr[r] += arr[next];
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 입력
    int n, r, q, u, v;
    cin >> n >> r >> q;
    vector<int>arr(n + 1, 1);
    vector<vector<int>>tree(n + 1, vector<int>(0));

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }


    dfs(r, 0,tree, arr);

    // 출력
    while (q--) {
        cin >> u;
        cout <<arr[u] << '\n';
    }
}