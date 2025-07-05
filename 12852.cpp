#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;

int main() {

    int N,K;

    cin>>N>>K;

    vector<int> visited(MAX, -1);     // 최단 시간
    vector<int> count(MAX, 0);        // 경우의 수

    queue<int> q;
    q.push(N);
    visited[N] = 0;
    count[N] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : {curr - 1, curr + 1, curr * 2}) {
            if (next < 0 || next >= MAX) continue;

            // 처음 방문하는 경우
            if (visited[next] == -1) {
                visited[next] = visited[curr] + 1;
                count[next] = count[curr];
                q.push(next);
            }
                // 같은 시간에 도달하는 또 다른 경로가 있는 경우
            else if (visited[next] == visited[curr] + 1) {
                count[next] += count[curr];
            }
        }
    }

    cout << visited[K] << '\n';
    cout << count[K] << '\n';

    return 0;
}