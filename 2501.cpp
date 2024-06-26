#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> A;
    int N,K;
    cin>>N>>K;

    for(int i=1; i<=N; i++){
        if(N%i==0){
            A.push_back(i);
        }
    }
    if(A.empty()){
        cout<<0;
    }
    else{
        cout<<A[K-1];
    }
    return 0;
}