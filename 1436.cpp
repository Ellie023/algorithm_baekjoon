#include <iostream>
#include "string"
using namespace std;

int main() {

    int n;
    int cnt=0;
    cin>>n;

    for(int i=666; ; i++){
        int tmp=i;
        while (tmp>=666){
            if(tmp%1000==666){
                cnt++;//666이면 count
                break;
            }
            tmp/=10;
        }
        if(n==cnt){
            cout<<i;//출력
            return 0;
        }
    }

    return 0;
}