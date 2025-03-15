#include <iostream>

using namespace std;

bool count(string s){

}

int main() {

    int N,M;
    string S;

    cin>>N>>M;
    cin>>S;
    int ans=0;
    int flag=0;
    for(int i=1; i<M-1; i++)
    {
        if(S[i]=='O'&&S[i-1]=='I'&&S[i+1]=='I'){
            flag++;
            if(flag==N){
                ans++;
                flag--;
            }
            i++;
        }
        else{
            flag=0;
        }
    }

    cout<<ans;
    return 0;
}