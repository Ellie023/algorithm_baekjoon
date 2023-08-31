#include <iostream>
#include "string"
using namespace std;


int main() {

    string s;

    int count=0;
    cin>>s;
    for(int i=s.length()-1; i>=0; i--) {
        char ch=s[i];
        if(ch=='='){
            ch=s[i-1];
            if(ch=='c'||ch=='s'){
                i--;
            }
            else if(ch=='z'){
                ch=s[i-2];
                if(ch=='d'){
                    i-=2;
                }
                else
                    i--;
            }

        }
        else if(ch=='-') {
            ch = s[i - 1];
            if (ch == 'c' || ch == 'd') {
                i--;
            }
        }
        else if(ch=='j'){
            ch = s[i - 1];
            if(ch=='l'||ch=='n'){
                i--;
            }
        }
        count++;
    }
    cout<<count;
    return 0;
}