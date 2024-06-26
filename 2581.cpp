#include <iostream>

using namespace std;

int main() {

    int N,M;

    cin>>N>>M;

    int sum=0;
    int min=M;
    for(int i=N; i<=M; i++){
        int j;
        for(j=2; j<i; j++){
            if(i%j==0){
                break;
            }

        }
        if(i==j){
            sum+=i;
            if(min>i){
                min=i;
            }
        }
    }
    if(sum==0){
        cout<<"-1";
    }
    else {
        cout << sum << '\n' << min;
    }
    return 0;
}