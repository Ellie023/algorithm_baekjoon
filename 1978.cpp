#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int N;
    cin>>N;
    queue<int> A;
    int count=0;


int i;
    while(N--){
        int num;
        cin>>num;

        for(i=2; i<num; i++){

            if(num%i==0){
                break;
            }

        }
        if(i==num){
            count++;
        }
    }
    cout<<count;
    return 0;
}