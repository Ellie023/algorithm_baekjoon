#include <iostream>
#include "queue"

using namespace std;

void calculate(priority_queue<int> &heap,int a){

    int b;
    if(a==0){
        if(heap.empty()){//아무것도 없으면
            cout<<"-1\n";
        }
        else{//가장 좋은 선물
            cout<<heap.top()<<'\n';
            heap.pop();
        }
    }
    else{//a가 0이 아니다
        while(a--){
            cin>>b;//충전
            heap.push(b);
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,a;
    priority_queue<int> heap;
    cin>>n;//입력
    while(n--){
        cin>>a;//입력
        calculate(heap,a);//연산
    }

    return 0;
}