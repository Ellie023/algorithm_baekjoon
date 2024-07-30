#include <iostream>
#include <vector>
using namespace std;
vector<bool> window;


int main() {

    int n;
    cin>>n;

    int count=0;

    for(int i=1; i*i<=n; i++) {

        count++;
    }

    cout<<count;

    return 0;
}