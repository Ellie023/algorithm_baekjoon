#include <iostream>
#include <algorithm>
using namespace std;

int tree[100000];
int tree_distance[100000];

int Euclidean(int a,int b){

    if(b==0){
        return a;
    }
    else{
        return Euclidean(b,a%b);
    }
}

int main() {

    int n;
    int gcd=0;
    int count=0;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>tree[i];
    }
    sort(tree,tree+n);
    for(int i=0; i<n-1; i++){
        tree_distance[i]=tree[i+1]-tree[i];
    }
    gcd=tree_distance[0];

    for(int i=1; i<n-1; i++){
        gcd=Euclidean(gcd,tree_distance[i]);
    }

    for(int i=0; i<n-1; i++){
        count+=(tree_distance[i]/gcd)-1;
    }
    cout<<count;
    return 0;
}