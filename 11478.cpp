#include <iostream>
#include <set>
using namespace std;

int main() {

    set<string> set;
    string s;
    cin>>s;

    for(int i=0; i<s.length(); i++){
        for(int j=i; j<s.length(); j++){
            set.insert(s.substr(i,j-i+1));
        }
    }

    cout<<set.size();
    return 0;
}