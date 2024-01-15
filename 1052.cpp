#include <iostream>

using namespace std;

const int MAX=26;
int bitCount(int n){
    int cnt =0;
    for(int i=0; i<MAX; i++){
        if(n&(1<<i)){
            cnt++;
        }
    }
    return cnt;
}
int minCount(int n, int k){
    int required=0;//최소 물병의 개수
    while (true){
        if(bitCount(n+required)<=k){
            return required;
        }
        required++;
    }
}
int main() {

    int n,k;

    cin>>n>>k;//입력

    cout<<minCount(n,k);
    return 0;
}