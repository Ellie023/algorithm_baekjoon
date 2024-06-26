#include <iostream>

using namespace std;

int main() {

    int a,b;
    cin>>a>>b;
    int count=0;
    while(1) {
        if(a>b){
            cout<<"-1";
            return 0;
        }
        if(b==a){
            count++;
            break;
        }
        if(b%10==1){
            b--;
            b/=10;
        }
        else if(b%2==0){
            b/=2;
        }

        else{
            cout<<"-1";
            return 0;
        }
        count++;
    }
    cout<<count;
    return 0;
}