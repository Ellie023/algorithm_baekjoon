#include <iostream>

using namespace std;
int n,m;
int arr[9]={0,};
bool visited[9]={0,};

void dfs(int num,int cnt) {//1
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
            cout << '\n';
            return;
        }
        for (int i = num; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[cnt] = i;
                dfs(i + 1, cnt + 1);
                visited[i] = false;
            }
        }
}

int main() {
    cin>>n>>m;
    dfs(1,0);
    return 0;
}