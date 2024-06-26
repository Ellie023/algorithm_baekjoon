#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n,a;
    cin>>n>>a;
    string s;

    int i=0;
    while(n){
        int tmp=n%a;
        if(tmp>9){
            tmp=tmp-10+'A';
            s+=tmp;
        }
        else{
            s+=tmp+'0';
        }
        n/=a;
    }
    reverse(s.begin(),s.end());

    cout<<s<<'\n';

    return 0;
}