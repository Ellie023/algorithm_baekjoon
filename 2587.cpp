#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v(5,0);
    int result=0;
    for(int i=0; i<5; i++){
        cin>>v[i];
        result+=v[i];
    }
    sort(v.begin(),v.end());
    cout<<result/5<<'\n'<<v[2];
    return 0;
}