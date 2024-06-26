#include <iostream>
#include "queue"
using namespace std;

int result(int n){
    int cnt=99;
    for(int i=100; i<=n; i++){
        int hun=i/100;
        int ten=(i/10)%10;
        int one=i%10;

        if((hun-ten)==(ten-one)){
            cnt++;
        }
    }
    return cnt;
}

int main() {

    int n;

    cin>>n;

    if(n<=99){
        cout<<n;
    }
    else{
        cout<<result(n);
    }
    return 0;
}