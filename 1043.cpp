#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> trueP;
vector<vector<int>> party;

int result;

int find(int a){
    if(parent[a]==a){
        return a;
    }
    else{
        return parent[a]= find(parent[a]);
    }
}

void unionfunc(int a,int b){
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

    int N,M,T;
    cin>>N>>M>>T;

    trueP.resize(T);

    for(int i=0; i<T; i++){
        cin>>trueP[i];
    }

    party.resize(M);

    for(int i=0; i<M; i++){
        int party_size;
        cin>>party_size;

        for(int j=0; j<party_size; j++){
            int temp;
            cin>>temp;
            party[i].push_back(temp);
        }
    }
    parent.resize(N+1);
    for(int i=0; i<=N; i++){
        parent[i]=i;
    }
    for(int i=0; i<M; i++){
        int firstpeople=party[i][0];
        for(int j=1; j<party[i].size(); j++){
            unionfunc(firstpeople,party[i][j]);
        }
    }
    for(int i=0; i<M; i++){
        bool isPossible= true;
        int cur=party[i][0];
        for(int j=0; j<T; j++){
            if(find(cur)==find(trueP[j])){
                isPossible= false;
                break;
            }
        }
        if(isPossible){
            result++;
        }
    }
    cout<<result;
    return 0;
}