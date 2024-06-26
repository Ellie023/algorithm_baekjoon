#include "queue"
#include "vector"
#include <iostream>
#in
using namespace std;
void balance(priority_queue<int>& max_pq, priority_queue<int, vector<int>, greater<>>& min_pq){
    int M,m;
    M=max_pq.top();
    m=min_pq.top();

    if(M>m){
        max_pq.pop();
        min_pq.pop();
        max_pq.push(m);
        min_pq.push(M);
    }
    return;
}
int main() {

    ios::sync_with_stdio(false);

    int n,num;
    cin>>n;
    priority_queue<int>max_pq;
    priority_queue<int,vector<int>,greater<>>min_pq;

    while (n--){
        cin>>num;
        if(max_pq.size()>min_pq.size()){
            min_pq.push(num);
        }
        else{
            max_pq.push(num);
        }
        if(!max_pq.empty()&&!min_pq.empty()){
            balance(max_pq,min_pq);
        }
        cout<<max_pq.top()<<"\n";
    }

    return 0;
}