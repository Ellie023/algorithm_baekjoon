#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int n;
    cin>>n;//입력
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];//입력
    }
    sort(v.begin(),v.end());//오름차순으로 정렬
    int findgcd=v[1]-v[0];//나머지가 같으므로 (두 수의 차)를 나눈 나머지가 0이다
    for(int i=2; i<n; i++) {//두 수의 차가 공약수 그 중 최대공약수를 찾기
        findgcd = gcd(findgcd, v[i]-v[i-1]);
    }
    vector<int> gcd_v;
    for (int i = 2; i*2 <=findgcd; i++)//최대공약수의 약수들
    {
        if (findgcd % i == 0)
        {
            gcd_v.push_back(i);
        }
    }
    gcd_v.push_back(findgcd);
    for (int i = 0; i < gcd_v.size(); i++)
    {
        cout << gcd_v[i] << " ";
    }
    return 0;
}