#include <iostream>
#include <deque>
#include <vector>

using namespace std;

const int MAX=100001;

int dfs(int N, int K){
    vector<int> visited(MAX,-1);
    deque<int> dq;

    dq.push_back(N);
    visited[N]=0;
    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur == K) return visited[cur];

        // 순간이동 (0초)
        if (cur * 2 < MAX && visited[cur * 2] == -1) {
            visited[cur * 2] = visited[cur];
            dq.push_front(cur * 2);
        }

        // 걷기 (1초)
        if (cur - 1 >= 0 && visited[cur - 1] == -1) {
            visited[cur - 1] = visited[cur] + 1;
            dq.push_back(cur - 1);
        }

        if (cur + 1 < MAX && visited[cur + 1] == -1) {
            visited[cur + 1] = visited[cur] + 1;
            dq.push_back(cur + 1);
        }
    }

    return -1; }

int main() {
    int N, K;
    cin >> N >> K;

    cout << dfs(N, K) << endl;

    return 0;
}