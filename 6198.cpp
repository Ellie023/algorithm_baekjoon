#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    int n;
    stack<int> s;

    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    s.push(0);
    int x;
    long long sum=0;
    for(int i=1; i<n;i++){
        while(!s.empty()&&arr[i]>=arr[s.top()]){
          x=s.top();
            s.pop();
        }

        s.push(i);
    }

    cout<<sum;
    return 0;
}