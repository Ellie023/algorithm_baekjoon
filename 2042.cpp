#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static vector<long> tree;

void changeVal(int index,long val){
    long diff = val -tree[index];

    while(index>0){
        tree[index]=tree[index]+diff;
        index=index/2;
    }
}
void setTree(int i){
    while(i!=1){
        tree[i/2]+=tree[i];
        i--;
    }
}
long getSum(int s, int e){
    long partSum=0;
    while(s<=e){
        if(s%2==1){
            partSum=partSum+tree[s];
            s++;
        }
        if(e%2==0){
            partSum=partSum+tree[e];
            e--;
        }
        s/=2;
        e/=2;
    }
    return partSum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    int treeheight=0;
    int Length=n;

    while(Length!=0){
        Length/=2;
        treeheight++;
    }
    int treeSize =int(pow(2,treeheight+1));
    int leftNodeStartIndex=treeSize/2-1;

    tree.resize(treeSize+1);

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
            cout<<getSum(s,e)<<"\n";
        }
    }
    return 0;
}