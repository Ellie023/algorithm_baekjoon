#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,cmp,X;

    cin>>N;

    stack<int> s;

    for(int i=0; i<N; i++){
        cin>>cmp;
        if(cmp==1){
            cin>>X;
            s.push(X);
        }
        else if(cmp==2){
            if(!s.empty()){
                cout<<s.top()<<'\n';
                s.pop();
            }
            else{
                cout<<-1<<'\n';
            }
        }
        else if(cmp==3){
            cout<<s.size()<<'\n';
        }
        else if(cmp==4){
            cout<<(s.empty()?1:0)<<"\n";
        }
        else if (cmp==5){
            if (!s.empty()) {
                cout << s.top() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}