#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
int m,n;
int tomato[2000][2000];
int xy[4]={0,0,-1,1};
int xx[4]={-1,1,0,-1};

int count=0;

int check(){//bfs

    queue<int> tomato;

    for(int i=0; i<tomato.size(); i++){

    }

    if(m>=0&&n>=0&&)
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>m>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tomato[i][j];
        }
    }

    return 0;
}