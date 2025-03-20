#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

priority_queue<int,vector<int>,greater<int>> min_pq;
priority_queue<int,vector<int>,less<int>> max_pq;
map<int,int> cnt;

void insert(int n){
    min_pq.push(n);
    max_pq.push(n);
    cnt[n]++;
}
void deleteMin(){
    if(!min_pq.empty()){
        cnt[min_pq.top()]--;
        min_pq.pop();
    }
}
void deleteMax(){
    if(!max_pq.empty()){
        cnt[max_pq.top()]--;
        max_pq.pop();
    }
}
void clearPas(){
    while(!min_pq.empty()&&cnt[min_pq.top()]==0){
        min_pq.pop();
    }
    while(!max_pq.empty()&&cnt[max_pq.top()]==0){
        max_pq.pop();
    }
}
int main() {

    int T,k,n;
    char c;

    cin>>T;
    while(T--){
        while(!min_pq.empty()){
            min_pq.pop();
        }
        while(!max_pq.empty()){
            max_pq.pop();
        }
        cnt.clear();
        cin>>k;
        for(int i=0; i<k; i++){
           cin>>c>>n;
           if(c=='I'){
               insert(n);
           }
           else{
               if(n==1) deleteMax();
               else deleteMin();
               clearPas();
           }
        }
        clearPas();
        if(min_pq.empty()||max_pq.empty()){
            cout<<"EMPTY"<<'\n';
        }
        else{
            cout<<max_pq.top()<<" "<<min_pq.top()<<'\n';
        }
    }
    return 0;
}