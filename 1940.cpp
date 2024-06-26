#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> A(n,0);

    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    sort(A.begin(),A.end());
    int count =0;
    int i=0;
    int j=n-1;
    while(i<j){
        if(A[i]+A[j]<m){
            i++;
        }
        else if(A[i]+A[j]>m){
            j--;
        }
        else{
            count++;
            i++;
        }
    }
    cout<<count<<"\n";

    return 0;
}