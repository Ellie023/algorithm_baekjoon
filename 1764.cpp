#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> e,l;

    int n,m;

    string input;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>input;
        e.push_back(input);
    }
    sort(e.begin(),e.end());

    for(int i=0; i<m; i++){
        cin>>input;
        if(binary_search(e.begin(),e.end(),input)){
            l.push_back(input);
        }
    }

    sort(l.begin(),l.end());
    cout<<l.size()<<'\n';

    for(auto o:l){
        cout<<o<<'\n';
    }
    return 0;
}