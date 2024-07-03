#include <iostream>
#include <vector>

using namespace std;
int main() {

    int N;
    int T,P;
    vector<int> size(6,0);
   int count=0;
    cin>>N;

    for(int i=0; i<6; i++){
        cin>>size[i];
    }
    cin>>T>>P;

    int num;

    for(int i=0; i<6; i++){
        count+=(size[i]+T-1)/T;
    }
    cout<<count<<'\n';
    cout<<N/P<<' '<<N%P;

    return 0;
}