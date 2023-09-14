#include <iostream>
#include "vector"
using namespace std;
const int MAX=1000000;

vector<bool> findPrime(){//배열의 인덱스가 소수인지 아닌지 판별
    vector<bool> primes(MAX+1, true);
    primes[0] = primes[1] = false;
    for(int i=2; i<=MAX; i++){
        if(!primes[i]){//지운 값은 패스
            continue;
        }
        for(int j=i*2; j<=MAX; j+=i){//i*i부터

            primes[j]=false; //지우기
        }
    }
    return primes;
}
vector<int> getPrimes(vector<bool> &prime){//소수들을 배열에 모으기
    vector<int> num;
    for(int i=3; i<MAX; i++){
        if(prime[i]){
            num.push_back(i);//소수인 인덱스를 배열에 저장
        }
    }
    return num;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> is_prime=findPrime();//배열의 인덱스가 소수?
    vector<int> primes= getPrimes(is_prime);//소수들을 집합
    int n;
    while (1){
        cin>>n;
        if(n==0){
            break;
        }
        bool isPrint= false;

        for(int i=0; i<primes.size()&&primes[i]<n; i++) {
                if (is_prime[n - primes[i]])//n-(i번째 소수)는 소수인가?
                {
                    cout<<n<<" = "<<primes[i]<<" + "<<n-primes[i]<<'\n';
                    isPrint=true;
                    break;
                }
            }
        if (!isPrint) {cout << "Goldbach's conjecture is wrong.\n";}
        }

    return 0;
}