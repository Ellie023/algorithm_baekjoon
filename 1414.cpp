#include <iostream>
#include <queue>
using namespace std;

vector<int> parent;

typedef struct Edge{
    int s,e,v;
    bool operator>(const Edge &temp) const{
        return v>temp.v;
    }
}Edge;
int find(int a){
    if(a==parent[a]){
        return a;
    }
    else{
        return parent[a]=find(parent[a]);
    }
}

void muion(int a, int b){

    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }

}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,sum=0;

    cin>>n;
    priority_queue<Edge,vector<Edge>,greater<Edge>>  pq;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char tempC =cin.get();
            if(tempC=='\n'){
                tempC=cin.get();
            }
            int temp=0;
            if(tempC>='a'&&tempC<='z'){
                temp=tempC-'a'+1;
            }
            else if(tempC>='A'&&tempC<='Z'){
                temp=tempC-'A'+27;
            }
            sum+=temp;
            if(i!=j&&temp!=0){
                pq.push(Edge{i,j,temp});
            }
        }
    }
    parent.resize(n);

    for(int i=0; i<n; i++){
        parent[i]=i;
    }
    int useEdge=0;
    int result=0;
    while(!pq.empty()){
        Edge now=pq.top();
        pq.pop ();
        if(find(now.s)!=find(now.e)){
            muion(now.s,now.e);
            result+=now.v;
            useEdge++;
        }
    }
    if(useEdge==n-1){
        cout<<sum-result<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }
    return 0;
}