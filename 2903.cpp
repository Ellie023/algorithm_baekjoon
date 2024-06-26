#include <iostream>

using namespace std;

int main() {

    int n,x=2;

    cin>>n;
    while(n--){
        x*=2;
        x-=1;
    }
    x*=x;

    cout<<x;
    return 0;
}
/*4 9 25
 * 2 3 5
 */