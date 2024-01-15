#include <iostream>
#include "queue"
using namespace std;

const int MAX=200000;

vector<int> v[MAX];
int rumor[MAX]={-1,};

int count_rumor(int x){
    int cnt=0;

    for(int i=0; i<v[x].size(); i++){
        if(rumor[v[x][i]]!=-1){
            cnt++;
        }
    }
    return cnt;
}

int main() {


    int n,p;
    queue<int> tq,q;q
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>p;
        v[i].push_back(p);
       while(1){
           if(p==0){
               break;
           }

       }
    }


    int n;


    return 0;
}