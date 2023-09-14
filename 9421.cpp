#include <iostream>
#include "vector"
#include "map"
const int MAX=1000000;
using namespace std;
vector<bool> findPrime(){//배열의 인덱스가 소수인지 아닌지 판별
    vector<bool> primes(MAX+1, true);
    primes[0] = primes[1] = false;
    for(int i=2; i<=MAX; i++){
        if(!primes[i]){//지운 값은 패스
            continue;
        }
        for(int j=i*2; j<=MAX; j+=i){//i*i부터
            if(!primes[j]) {
                continue;//지운 값은 패스
            }
            primes[j]=false; //지우기
        }
    }
    return primes;
}
vector<int> getPrimes(vector<bool> &prime){//소수들을 배열에 모으기
    vector<int> num;
    for(int i=2; i<MAX; i++){
        if(prime[i]){
            num.push_back(i);//소수인 인덱스를 배열에 저장
        }
    }
    return num;
}
bool result(int n){
    map<int,bool> visited;

    int temp=n;
    while(1){
        int sum=0;
    while (temp)

    {

        sum += (temp % 10)*(temp % 10);

        temp /= 10;

    }
        if(sum==1){
            return true;}
        if(!visited.count(sum)) {
            visited[sum] = true;
        }
        else {
            return false;
        }
        temp=sum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<bool> is_prime=findPrime();//배열의 인덱스가 소수?
    vector<int> primes= getPrimes(is_prime);//소수들을 집합
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] > n)
            break;

        else {

            if (result(primes[i])) {

                cout << primes[i] << "\n";
            }
        }
    }
    return 0;
}