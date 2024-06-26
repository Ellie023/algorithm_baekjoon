#include <iostream>
#include <vector>
using namespace std;

const int INF = 987'654'321;

typedef pair<int, int> pii;

pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground){

    int h;
    int max=INF;
    for(int e = 0; e <= 256; e++){
        int x = 0; //build
        int y = 0; //remove
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(ground[i][j] > e) {
                    y += ground[i][j] - e;
                } else if(ground[i][j] < e){
                    x += e - ground[i][j];
                }
            }
        }
        if(y + b >= x) {
            int time = y * 2 + x;
            if(max >= time){
                max = time;
                h = e;
            }
        }
    }
    return {max,h};
}

int main() {
    int n,m,b;
    int h;
    int max=INF;
// 입력
    cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
        }
    }

    pii answer = makeGroundEven(n, m, b, ground);

    // 출력
    cout << answer.first << " " << answer.second << '\n';
    return 0;
}