#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    while(1){
        cin>>n;
        if(n==-1){
            break;
        }
        cout<<n;
        vector<int> A;
        for(int i=1; i<=n/2; i++){
            if(n%i==0){
                A.push_back(i);
            }
        }
        int sum=0;
        bool flag= false;
        for(int i=0; i<A.size(); i++){
            sum+=A[i];
        }
        if(sum==n){
            flag= true;
            cout<<" = "<<A[0];
            for(int j=1; j<A.size(); j++){
                cout<<" + "<<A[j];
            }
            cout<<'\n';
        }
        if(flag== false){
            cout<<" is NOT perfect."<<'\n';
        }
        A.clear();

    }
    return 0;
}