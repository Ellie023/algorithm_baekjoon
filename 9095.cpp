#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int sum[12];

int recursive(int num){
    if(num==1||num==2){
        return num;
    }
    if(num==3){
        //1+2, 1+1+1,2+1,3
        return 4;
    }
    if(sum[num]!=-1){
        return sum[num];
    }
    return sum[num]= recursive(num-1)+ recursive(num-2)+ recursive(num-3);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a;

    cin>>n;

    while (n--){
        cin>>a;
        memset(sum,-1,sizeof(sum));
        cout<<recursive(a)<<'\n';
    }
    return 0;
}