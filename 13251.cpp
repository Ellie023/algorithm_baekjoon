#include <iostream>

using namespace std;

int M,K,T;
int D[51];
double probability[51];
double ans=0.0;
int main() {

    cin>>M;
    for(int i=0; i<M; i++){
        cin>>D[i];
        T+=D[i];
    }
    cin>>K;

    for(int i=0; i<M; i++){
        if(D[i]>=K){
            probability[i]=1.0;
            for(int k=0; k<K; k++){
                probability[i]*=(double)(D[i]-k)/(T-k);
            }
        }
        ans+=probability[i];
    }
    cout<<fixed;
    cout.precision(9);
    cout<<ans;

    return 0;
}