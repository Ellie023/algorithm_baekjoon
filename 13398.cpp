#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> A,L,R;

int main() {

    cin>>n;
    A.resize(n);

    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    L.resize(n);
    L[0]=A[0];
    int result=L[0];

    for(int i=1; i<n; i++){
        L[i]=max(A[i],L[i-1]+A[i]);
        result=max(result,L[i]);
    }
    R.resize(n);
    R[n-1]=A[n-1];
    for(int i=n-2; i>=0; i++){
        R[i]=max(A[i],R[i+1]+A[i]);
    }
    for(int i=1; i<n-1; i++){
        int temp=L[i-1]+R[i+1];
        result=max(result,temp);
    }
    cout<<result;
    return 0;
}
