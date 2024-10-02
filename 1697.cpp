#include <iostream>
#include <queue>

using namespace std;


const int MAX =100001;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    int minsec[MAX]={0,};
    int NowN,sec=0;

    queue<int> q;
    q.push(n);

    while(!q.empty()){
        NowN=q.front();
        q.pop();
        if(NowN<0||NowN>MAX) continue;

        if(NowN==k){
            cout<<minsec[NowN];
            break;
        }
        if(NowN-1>=0&&minsec[NowN-1]==0){
            minsec[NowN-1]=minsec[NowN]+1;
            q.push(NowN-1);
        }
        if(NowN+1<=MAX&&minsec[NowN+1]==0){
            minsec[NowN=1]=minsec[NowN]+1;
            q.push(NowN+1);
        }
        if(2*NowN<=MAX&&minsec[NowN-1]==0){
            minsec[NowN*2]=minsec[NowN]+1;
            q.push(NowN*2);
        }

    }
    return 0;
}