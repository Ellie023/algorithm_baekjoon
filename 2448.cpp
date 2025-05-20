#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> draw_star(int n){
    if(n==3){
        return{
            "  *  ",
            " * * ",
            "*****"
        };
    }
    vector<string> prev = draw_star(n/2);
    vector<string> result;

    for(string s:prev){
        result.push_back(string(n/2,' ')+s+string(n/2,' '));
    }
    for(string s:prev){
        result.push_back(s+" "+s);
    }

    return result;

}

int main() {
    int n;
    cin>>n;
    vector<string> star_pattern=draw_star(n);

    for(const string& line : star_pattern){
        cout<<line<<'\n';
    }

    return 0;
}