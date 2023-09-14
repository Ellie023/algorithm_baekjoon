#include <iostream>
#include "cmath"
#include <vector>
using namespace std;

int main() {

    vector<vector<int>>n(9,vector<int>(9,0));

    int a=0,b=0,max=0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>n[i][j];
            if(n[i][j]>max){
                a=i;
                b=j;
                max=n[i][j];
            }
        }
    }
cout<<max<<'\n'<<a+1<<" "<<b+1;
    return 0;
}