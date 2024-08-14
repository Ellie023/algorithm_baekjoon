#include <iostream>
#include <queue>
using namespace std;

static int dr[]={-1,0,1,0};
static int dc[]={0,1,0,-1};
static int map[101][101];
static bool visited[101][101]={false};
static vector<int> parent;
static int N,M,sNum;
static vector<vector<pair<int,int>>>  sumlist;
static vector<pair<int,int>> mlist;

typedef struct Edge{
    int s,e,v;
    bool operator>(const Edge& temp){//연산자 오버로딩
        return v>temp.v; //temp.v를 어디에 둘 지 결정한다.
    }
}Edge;

static priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<)

    return 0;
}