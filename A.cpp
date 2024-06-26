#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a,b,c,d;
    cin>>n;
    while (n--){
        int sum=0;
        cin>>a>>b>>c>>d;
        if(a*c<=b*d){
            cout<<b*d<<'\n';
        }
        else{
            sum+=b*d;
            int temp=0;
            temp=(a*c-b*d);
            if(temp%2==0){
                sum+=temp/2;
            }
            else{
                sum+=temp/2+1;
            }
            cout<<sum<<'\n';
        }
    }
    return 0;
}