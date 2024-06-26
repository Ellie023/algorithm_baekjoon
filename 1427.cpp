#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin>>str;
    vector<int> A(str.size(),0);
    for(int i=0; i<str.size(); i++){
        A[i]=stoi(str.substr(i,1));
    }
    for(int i=0; i<str.length(); i++){
        int max=i;
        for(int j=i+1; j<str.length(); j++){
            if(A[j]>A[max]){
                max=j;
            }
        }
        if(A[i]<A[max]){
            int temp=A[i];
            A[i]=A[max];
            A[max]=temp;
        }
    }
    for(int i=0; i<A.size(); i++){
        cout<<A[i];
    }
    return 0;
}