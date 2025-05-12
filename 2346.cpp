#include <iostream>
#include <deque>
#include <vector>

using namespace
std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    deque<pair<int,int>> dq;

    for(int i=1; i<=n; i++){
      int num;
      cin>>num;
      dq.push_back({i,num});
    }

    vector<int> result;

    while(!dq.empty()){
        auto[index,move]=dq.front();
        dq.pop_front();
        result.push_back(index);
        if(dq.empty()) break;
        if(move>0){
            for(int i=0; i<move-1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            for(int i=0; i<-move; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    for(int x:result){
        cout<<x<<' ';
    }
    return 0;
}