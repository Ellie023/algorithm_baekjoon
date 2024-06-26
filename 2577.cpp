#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    vector<int> A(10,0);
    int n;
    long long sum=1;
    for(int i=0; i<3; i++){
        cin>>n;
        sum*=n;
    }
    while (sum>0){
        int c;
        c=sum%10;
        A[c]++;
        sum/=10;
    }
    for(int i=0; i<10; i++){
        cout<<A[i]<<'\n';

    }
    return 0;
}