#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<long long,string>> rank(8);

    string color;
    for(int i=0; i<8; i++){
        vector<string> A;
        string buffer;
        string input;
        rank[i].first=0;
        cin>>input>>color;
        istringstream ss(input);
        while (getline(ss,buffer,':')){
            A.push_back(buffer);
        }
        long long number = stoll(A[0] + A[1] + A[2]);
        rank[i] = make_pair(number, color);
    }
    int score=1;
    sort(rank.begin(),rank.end());
    int red=0,blue=0;
    for(int i=7; i>=0; i--){
        if(rank[i].second=="B"){
            blue+=score;
        } else{
            red+=score;
        }
        if(i<=2){
            score+=2;
        }
        else{
        score++;}
    }
    if(red>blue){
        cout<<"Red";
    }
    else if(red<blue){
        cout<<"Blue";
    }
    return 0;
}