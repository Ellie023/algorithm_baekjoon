#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE=26;

int main() {

    vector<int> count(SIZE,0);
    string str;
    cin>>str;

    for(int i=0; i<str.size(); i++){
        count[str[i]-'A']++;
    }
    string part1="",part2="",part3="";
    for(int i=0; i<26; i++){
        if(count[i]%2==1){
            if(part2.size()==1){
                cout<<"I'm Sorry Hansoo";
                return 0;
            }
            part2=(char)(i+'A');
        }
        for(int j=0; j<count[i]/2; j++){
            part1+=(char)(i+'A');
            part3=(char)(i+'A')+part3;
        }

    }
    cout<<part1+part2+part3;
    return 0;
}