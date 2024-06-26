#include <iostream>
#include "vector"
using namespace std;
typedef pair<int,int> ic;

ic solve(vector<int> v){
    int Q=0,r=0; //총힙을 2로 나눴을 때 몫과 나머지
    for(int i=0; i<v.size(); i++){
        Q+=v[i]/2;
        r+=v[i]%2;
    }
    return {Q,r};
}
int main() {

    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    ic water=solve(v);
    if(((water.first-water.second)%3==0)&&water.first>=water.second){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}