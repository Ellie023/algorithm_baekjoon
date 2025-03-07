#include <iostream>

using namespace std;

int main() {

    int n;
    cin>>n;
    int box[1000];

    box[1]=1;
    box[2]=3;
    for(int i=3; i<=n; i++){
        box[i]=(box[i-1]+box[i-2]*2)%10007;
    }
    cout<<box[n];
    return 0;
}