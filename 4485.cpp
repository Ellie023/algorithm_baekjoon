#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int arr[130][130];
int dist[130][130];

void bfs(int n){
    queue <pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0]=arr[0][0];

    while (!q.empty()){
        int x=q.front().second;
        int y=q.front().first;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
          if(ny>=0&&ny<n&&nx>=0&&nx<n){
              if(dist[ny][nx]>dist[y][x]+arr[ny][nx]){
                  dist[ny][nx]=dist[y][x]+arr[ny][nx];
                  q.push(make_pair(ny,nx));
              }
          }
        }
    }
}
int main() {


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count=1;
    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
                dist[i][j] = 1000000000;
            }
        bfs(n);
        cout << "Problem " << count++ << ": " << dist[n - 1][n - 1] << "\n";
    }
    return 0;
}