#include <iostream>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;
    cin>>a>>b;

    string c="";
    bool flag= false;
    for(int i=0; i<a.length(); i++){
        c+=a[i];
        if(c.length()>=b.length()){
            flag= true;
            for(int j=0;j<b.length(); j++){
                int different =c.length()-b.length();
                if(c[different+j]!= b[j]){
                    flag= false;
                    break;
                }
            }
            if(flag){
                c.erase(c.end()-b.length(),c.end());
            }
        }


    }
    if(c.empty()){
        cout<<"FRULA"<<'\n';
    }
    else{
        cout<<c;
    }
    return 0;
}