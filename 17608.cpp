#include <iostream>
#include <stack>

using namespace std;

int main() {

    stack<int> s;
    int n;
    cin>>n;
    int input;
    for(int i=0; i<n; i++){
        cin>>input;
        s.push(input);
    }
    int count=1;
    input=s.top();
    s.pop();
    while (!s.empty()){
        if(input<s.top()){
            input=s.top();
            count++;
        }
        s.pop();
    }
    cout<<count;
    return 0;
}