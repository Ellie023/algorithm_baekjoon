#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int a){
    if(a==parent[a]){
        return a;
    }
    else{
        return parent[a]=find(parent[a]);
    }
}

void unionfind(int a, int b){
    a=find(a);
    b=find(b);

    if(a!=b){
        parent[b]=a;
    }
}

bool checkSame(int a,int b){

    a=find(a);
    b= find(b);

    if(a==b) {
        return true;
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;

    cin>>N>>M;

    parent.resize(N+1);

    for(int i=0; i<=N; i++){
        parent[i]=i;
    }
    for(int i=0; i<M; i++){
        int question,a,b;
        cin>>question>>a>>b;

        if(question==0){
            unionfind(a,b);
        }
        else{
            if(checkSame(a,b)){
              cout<<"YES"<<"\n";}
            else {
               cout << "NO" << "\n";
                }
        }
        }


    return 0;
}