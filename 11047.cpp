#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int> A(n);

    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int count=0;

    for(int i=n-1; i>=0; i--){
        if(A[i]<=k){
            count+=(k/A[i]);
            k=k%A[i];
        }
    }
    cout<<count;

    return 0;
}