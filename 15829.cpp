#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    cin>>L;
    string v;

    long long sum=0;
    long long r=1;
    cin>>v;
    for(int i=0; i<L; i++){
        int ask=(int)v[i];
        ask-=96;
        sum=(sum+(ask*r))%123456789;
        r=(r*31)%1234567891;
    }
    cout<<sum%1234567891;
    return 0;
}