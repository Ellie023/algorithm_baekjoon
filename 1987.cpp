#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R,C;
vector<string> board;
bool visitedAlpha[26];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int maxCount=0;

void dfs(int x,int y, int count){
    maxCount=max(maxCount,count);

    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0&&nx<R&&ny>=0&&ny<C){
            int alphaIdx=board[nx][ny]-'A';
            if(!visitedAlpha[alphaIdx]){
                visitedAlpha[alphaIdx]=true;
                dfs(nx,ny,count+1);
                visitedAlpha[alphaIdx]=false;
            }
        }
    }
}

int main() {

    cin>>R>>C;

    board.resize(R);
    for(int i=0; i<R; i++) {
        cin >> board[i];
    }

    visitedAlpha[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout<<maxCount<<'\n';

    return 0;
}