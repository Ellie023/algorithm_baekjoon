#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int a){
    if(a==parent[a]){
        return a;
    }
    else{
        return parent[a]= find(parent[a]);
    }
}

void unionfuc(int a, int b){
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

    int N,M;
    cin>>N>>M;

    int city[201][201];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>city[i][j];
        }
    }

    int route[1001];

    for(int i=1; i<=M; i++){
        cin>>route[i];
    }
    parent.resize(N+1);

    for(int i=1; i<=N; i++){
        parent[i]=i;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(city[i][j]==1){
                unionfuc(i,j);
            }
        }
    }

    int index=find(route[1]);
    bool connect= true;

    for(int i=2; i<=M; i++){
        if(index!=find(route[i])){
            cout<<"NO"<<'\n';
            connect= false;
            break;
        }
    }
    if(connect){
        cout<<"YES"<<"\n";
    }
    return 0;
}