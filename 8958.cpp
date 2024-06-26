#include <iostream>

using namespace std;

int main() {


    int sum;
    int n;
    cin>>n;

    string c;
    for(int i=0; i<n; i++) {
        cin >> c;
        sum=0;
        int d=1;
        for(int j=0; j<c.length(); j++){
            if(c[j]=='O'){
                sum+=d;
                d++;
            }
            else{
                d=1;
            }
        }
        cout << sum << '\n';

    }
    return 0;
}