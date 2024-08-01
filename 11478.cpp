#include <iostream>
#include <set>
using namespace std;

int main() {

    set<string> set;
    string s;
    cin>>s;

    for(int i=0; i<s.length(); i++){
        for(int j=0; j<s.length(); j++){
            set.insert(s.substr(i,j-1+1));
        }
    }

    cout<<set.size();
    return 0;
}