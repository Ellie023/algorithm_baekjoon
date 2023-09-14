#include <iostream>

using namespace std;

int main() {

    int n,k;

    cin>>n>>k;//입력

    if(n<=k){//옮길 수 있는 병의 개수가 더 큰 경수 안 사도 됨
        cout<<0<<'\n';
        return 0;
    }

    int i;
    for(i=0; ; i++){
        int count =0;
        int tmp=n;

        while (tmp){
            if(tmp%2){//n을 2로 나눠서 나머지가 존재한다
                count++;//물병을 산다.
            }
            tmp/=2;
        }
        if(count<=k){//산 물병이 k개 이하면 조건이 성립
            break;
        }
        n++;
    }
    //출력
    cout<<i<<'\n';
    return 0;
}