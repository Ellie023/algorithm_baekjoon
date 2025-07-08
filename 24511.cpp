#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int> arr(n,0);
    deque<int> deque;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        if(!arr[i]){
            deque.push_back(a);
        }
    }
    int m;
    cin>>m;
    while(m--){
        cin>>a;
        deque.push_front(a);
        cout<<deque.back()<<' ';
        deque.pop_back();
    }

    return 0;
}