#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    string color;
    stack<int> s;
    cin>>color;

    int sum=0;
    bool flag= true;
    while (color!="WWWW"){
        if(n==1){
            flag= false;
            break;
        }
        for(int i=3; i>=0; i--) {
            if (color[i] == 'B') {
                s.push(i + 1);
                while (i >= 0) {
                    if (color[i] == 'B') {
                        color[i] = 'W';
                    } else if (color[i] == 'W') {
                        color[i] = 'B';
                    }
                    i--;
                }
            }

        }
        sum++;
    }
    if(flag== false){
        cout<<'-1';
    }
    else{
        cout<<sum<<'\n';
        while (!s.empty()){
            cout<<s.top()<<'\n';
            s.pop();
        }
    }
    return 0;
}