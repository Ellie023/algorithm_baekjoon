#include <iostream>
#include "vector"
#include "set"
#include "queue"
using namespace std;

int main() {

    int n,m;
    cin>>n>>m;
    priority_queue<int> v;
    vector<int> a;
    for(int i=0; i<n; i++){
        int b;
        cin>>b;
        v.push(b);
        a.push_back(b);
    }

    for(int i=0; i<m; i++){
        cout<<v.top();

    }
    return 0;


}