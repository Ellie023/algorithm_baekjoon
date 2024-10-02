#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<long> tree;
static int MOD=1000000007;
void setTree(int i){
    while(i!=1){
        tree[i/2]=tree[i/2]*tree[i]%MOD;
        i--;
    }
}
void changeVal(int index,long val){
    tree[index]=val;
    while(index>1){
        index/=2;
        tree[index]=tree[index*2]%MOD*tree[index*2+1]%MOD;
    }
}
long getMul(int s, int e){
    long partMul=1;

    while(s<=e){
        if(s%2==1){
            partMul=partMul*tree[s]%MOD;
            s++;
        }
        if(e%2==0){
            partMul=partMul*tree[e]%MOD;
            e--;
        }
        s/=2;
        e/=2;
    }
    return partMul;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    int treeHeight=0;
    int Length=n;
    while(Length!=0){
        Length/=2;
        treeHeight++;
    }
    int treeSize=int(pow(2,treeHeight+1));
    int leftNodeStartIndex=treeSize/2-1;
    tree.resize(treeSize+1);
    fill(tree.begin(),tree.end(),1);
    for(int i=leftNodeStartIndex+1; i<=leftNodeStartIndex+n; i++){
        cin>>tree[i];
    }
    setTree(treeSize-1);

    for(int i=0; i<m+k; i++){
        long a,s,e;
        cin>>a>>s>>e;

        if(a==1){
            changeVal(leftNodeStartIndex+s,e);
        }
        else if(a==2){
            s+=leftNodeStartIndex;
            e+=leftNodeStartIndex;
            cout<<getMul(s,e)<<"\n";
        }
    }
    return 0;
}