#include <iostream>
#include <map>

using namespace std;

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m;
    map<string,string> map;

    cin>>n>>m;

    string a,b;

    for(int i=0; i<n; i++){
        cin>>a>>b;

        map[a]=b;
    }
    for(int i=0; i<m; i++){
        cin>>a;

        cout<<map[a]<<'\n';
    }


    return 0;
}