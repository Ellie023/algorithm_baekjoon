#include <iostream>
#include "string"

using namespace std;

const int ALL=(1<<21)-1;

int result(int bit,string order){
    if(order=="all"){
        bit=ALL;
    }
    else if(order=="empty"){
        bit=0;
    }
    else {
        int value;
        cin >> value;
        if (order == "add") {
            bit |= (1 << value);
        } else if (order == "remove") {
            bit &= ~(1 << value);
        } else if (order == "toggle") {//1이 홀수 즉 없으면 1, 1이 짝수, 즉 었으면 0
            bit ^= (1 << value);
        }
    }
    return bit;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string order;
    int a,bit=0;

    cin>>n;//입력

    while(n--){
        cin>>order;//연산입력
        if(order=="check"){//연산이 check면 출력
            cin>>a;
            if(bit&(1<<a)){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        else{//연산 수행
            bit=result(bit,order);
        }
    }
    return 0;
}