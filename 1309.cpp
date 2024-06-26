#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;

    int lion[100001];
    lion[0]=1;
    lion[1]=3;

    for(int i=2; i<=n; i++){
        lion[i]=lion[i-2]+lion[i-1]*2;
        lion[i]%=9901;
    }
    cout<<lion[n];

    return 0;
}

/*
 00 01 10
 3   2   2 =7
 7   5   5 = 17

 lion[1]=3
 lion[2]=1*3 +
 00 -> 3가지 01 10 00 2 2 3
 10 -> 2가지 00 01 3 2
 01 -> 2가지 00 10 3 2

 00 00 00 10 10 01 01
 01 10 00 00 01 10 10

 2 -> 3
 4 -> 7
 6 -> 17
 8 -> 41
 */