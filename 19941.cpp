#include <iostream>

using namespace std;

bool Eat(int start,int end, string hamburger){
    for(int j=start; j<=end; j++){
        if(j>=0&&j<hamburger.length()&&hamburger[j]=='H'){
            hamburger[j]='E';
            return true;
        }
    }
    return false;
}

int main() {

    int n,k;
    string hamburger;

    cin>>n>>k>>hamburger;

    int ans=0;
    for(int i=0; i<hamburger.length(); i++){
        if(hamburger[i]!='P'){
            continue;
        }
        if(Eat(i-k,i-1,hamburger)){
            ans++;//left
        }
        if(Eat(i+1,i+k,hamburger)){
            ans++;//right
        }
    }
    cout<<ans;

    return 0;
}