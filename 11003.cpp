#include <iostream>
#include <deque>
using namespace std;

typedef pair<int,int> node;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);;
    cout.tie(NULL);

    deque<node> mydeque;

    int N,L;

    cin>>N>>L;

    for(int i=0; i<N; i++){
        int now;
        cin>>now;
        while (mydeque.size()&&mydeque.back().first>now){
            mydeque.pop_back();
        }
        mydeque.push_back(node(now,i));
        if(mydeque.front().second<=i-L){
            mydeque.pop_front();
        }
        cout<<mydeque.front().first<<" ";
    }




    return 0;
}