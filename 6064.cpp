#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int lcm(int a,int b){
    return ((a*b)/gcd(a,b));
}

int main() {

    int T;
    cin>>T;


    while(T--){
        int result=-1;
        int N,M,x,y;
        cin>>N>>M>>x>>y;
        int max=lcm(N,M);

        for(int i=x; i<=max; i+=N){
            int ny =i%M;
            if(ny==0){
                ny=M;
            }
            if(ny==y){
                result=i;
                break;
            }
        }
        cout<<result<<'\n';
    }




    return 0;
}