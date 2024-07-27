#include <iostream>

using namespace std;

int main() {

    int a,b,c;
    string A,B;
    cin>>A>>B>>c;
    a= stoi(A);
    b=stoi(B);
    cout<<a+b-c<<'\n';
    cout<<stoi(A+B)-c;

    return 0;
}