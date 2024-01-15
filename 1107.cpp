#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {

    int n,m;
    int count=0;
    int currect=100;
    set<int> butter;
    for(int i=0; i<10; i++){
        butter.insert(i);
    }
    cin>>n>>m;
    if(n==100){
        cout<<"0";
        return 0;
    }
    int a;
    for(int i=0; i<m; i++){
        cin>>a;
        if(butter.find(a)!=butter.end()){
            butter.erase(a);
        }
    }

    return 0;
}