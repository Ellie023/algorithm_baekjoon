#include <iostream>
using namespace std;

int n, m;
int arr[9];

void dfs(int start, int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        arr[cnt] = i;
        dfs(i, cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    dfs(1, 0);
    return 0;
}
