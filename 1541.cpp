#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


vector<string> split(string input, char  delimiter){
    vector<string> result;
    stringstream mystream(input);
    string splidate(input);

    while (getline(mystream,splidate, delimiter)){
        result.push_back(splidate);
    }
    return result;
}

int mySum(string a){
    int sum=0;
    vector<string> temp=split(a,'+');
    for(int i=0; i<temp.size(); i++){
        sum+=stoi(temp[i]);
    }
    return sum;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans=0;
    string example;
    cin>>example;
    vector<string> str=split(example,'-');
    for(int i=0; i<str.size(); i++){
        int temp=mySum(str[i]);
        if(i==0){
            ans=ans+temp;
        } else{
            ans=ans-temp;
        }
    }
    cout<<ans<<'\n';
    return 0;
}