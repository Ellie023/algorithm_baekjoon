#include <iostream>
#include "string"
using namespace std;

int solution(int &n){
    int cnt=0;
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
            return i;
        }
    }
}

int main() {

    int n;

    cin>>n;

    cout<<solution(n);

    return 0;
}