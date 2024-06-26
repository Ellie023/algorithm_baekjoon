#include <iostream>

using namespace std;

int main() {

    int a,b;
    bool flag= true;
    string result="mixed";
    cin>>a;
    if (a == 1) {
        result="ascending";
    } else if (a == 8) {
        result="descending";
    } else {
        result="mixed";
    }
    for(int t=0; t<7; t++) {
    cin>>b;
    if(a<b){
        a++;
    } else if(a>b){
       a--;
    }
    if(a!=b){
        flag= false;
        break;
        }
    a=b;
}
    if(!flag){
        result="mixed";
    }
    cout<<result;
    return 0;
}