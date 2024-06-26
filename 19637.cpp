#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,power;
    map<int,string> character;
    string name;

    cin>>n>>m;
    while(n--){
        cin>>name>>power;
        if(character[power].empty()){
            character[power]=name;
        }
    }
    while(m--){
        cin>>power;
        cout<<character.lower_bound(power)->second<<"\n";
    }


    return 0;