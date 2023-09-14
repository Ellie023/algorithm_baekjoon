#include <iostream>
#include <vector>

const int MAX=5000000;
using namespace std;

vector<int>getprimes(){
    vector<int> primes(MAX+1,0);
    for(int i=2; i*i<MAX; i++){
        if(primes[i])
            continue;

        for(int j=i*i; j<=MAX; j+=i){
            if(!primes[j])
                primes[j]=i;
        }
    }
    return primes;

}
vector<int> getprimeFactors(int k, vector<int> &primes){
    vector<int> factors;

    while(primes[k]){
        factors.push_back(primes[k]);
        k/=primes[k];
    }
    factors.push_back(k);
    return factors;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n;
    vector<int> primes=getprimes();
    while (n--){
        cin>>k;

        vector<int> factors=getprimeFactors(k,primes);

        for(int num:factors){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    return 0;
}