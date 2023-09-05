#include <iostream>
#include <map>
#include "string"
using namespace std;

int gcditar(int a,int b){
    while(b){
        a%=b;
        swap(a,b);

    }
    return a;
}
int gdcRecur(int a, int b){
    if(b==0)
        return a;
    else{
        return (b, gdcRecur(b,a%b));
    }
}
int main()
{


    int a,b;
    cin>>a>>b;
    int gdc= gdcRecur(max(a,b),min(a,b));
    int lcm=a*b/gdc;
    cout<<gdc<<'\n'<<lcm;
    return 0;
}