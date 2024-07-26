#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    vector<int> year;
    vector<pair<int,char>> name;

    for(int i=0; i<3; i++){
        int input;
        cin>>input;
        int y;
        string s;
        cin>>y>>s;
        year.push_back(y%100);
        name.push_back(make_pair(input,s[0]));
    }
    sort(year.begin(),year.end());
    sort(name.begin(),name.end(),greater<>());
    for(int i=0; i<year.size(); i++){
        cout<<year[i];
    }
    cout<<'\n';
    for(int i=0; i<name.size(); i++){
        cout<<name[i].second;
    }
    return 0;
}