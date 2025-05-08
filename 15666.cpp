#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
int arr[9];

void dfs(int start, int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i < n; i++) {
        arr[depth] = nums[i];
        dfs(i, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());  // 정렬
    nums.erase(unique(nums.begin(), nums.end()), nums.end());  // 중복 제거
    n = nums.size(); // 중복 제거 후 길이로 업데이트

    dfs(0, 0);
    return 0;
}
