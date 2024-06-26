#include <iostream>
#include <queue>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> Q;
    int N;

    cin>>N;

    for(int i=0; i<N; i++){
        Q.push(i);
    }
    while (Q.size()>1){
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout<<Q.front();
    return 0;
}