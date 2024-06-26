#include <iostream>
#include "vector"
#include "cmath"
using namespace std;
long long search(int n,vector<long long> v){
    double speed=v[n-1];
    for (int i = n - 2; i >= 0; i--) {//뒤에서부터 배수 찾기
        speed = ceil(speed / v[i]) * v[i];
    }
    return speed;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,input;
    vector<double> v;

    //입력
    cin>>n;
    v.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    double result=search(n,v);
    //출력
    cout<<(long long)result;
    return 0;
}