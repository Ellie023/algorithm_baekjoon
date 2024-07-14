#include <iostream>

using namespace std;

int main() {

    int N;

    cin>>N;

    int a=0,b=0;
    for(int i=1; i<=N; i++){
        int x=i;
        while (x%2==0){
            a++;
            x/=2;
        }
        while (x%5==0){
           b++;
           x/=5;
       }
    }
    if(a==0||b==0){
        cout<<'0';
    }
    else if(a>b){
        cout<<b;
    } else{
        cout<<a;
    }
    return 0;
}