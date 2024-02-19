#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long Min,Max;
    cin>>Min>>Max;

    vector<bool> check(Max - Min + 1, false); //최댓값과 최솟값의 차이

    for(long long i=2; i*i<=Max; i++){
        long long pow=i*i; //제곱수
        long long start_index=Min/pow;
        if(Min%pow!=0){
            start_index++;
        }
        for(long long j = start_index; pow*j<=Max; j++){
            check[j*pow-Min]= true;
        }
    }
    int count=0;

    for(int i=0; i<=Max-Min; i++){
        if(!check[i]){
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}