#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

static vector<long> tree;

void setTree(int i){
    while(i!=1){
        if(tree[i/2]>tree[i]){
            tree[i/2]=tree[i];
        }
        i--;
    }
}
long getMin(int s,int e){
    long Min =LONG_MAX;
    while(s<=e){
        if(s%2==1){
            Min=min(Min,tree[s]);
            s++;
        }
        s/=2;
        if(e%2==0){
            Min=min(Min,tree[e]);
            e--;
        }
        e/=2;
    }
    return Min;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int treeheight=0;
    int length=n;

    while(length!=0){
        length/=2;
        treeheight++;
    }
    int treeSize=int(pow(2,treeheight+1));
    int leftNodeStartIndex=treeSize/2-1;

    tree.resize(treeSize+1);
    fill(tree.begin(),tree.end(),LONG_MAX);

    for(int i= leftNodeStartIndex+1; i<=leftNodeStartIndex+n; i++){
        cin>>tree[i];
    }
    setTree(treeSize-1);

    for(int i=0; i<m; i++){
        long s,e;
        cin>>s>>e;
        s+=leftNodeStartIndex;
        e+=leftNodeStartIndex;
        cout<<getMin(s,e)<<"\n";
    }
    return 0;
}