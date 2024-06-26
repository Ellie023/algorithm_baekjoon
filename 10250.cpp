#include <iostream>

using namespace std;

int main() {

    string a="";
    int n;
    int floor,room,guest;
    cin>>n;
    while (n--){
        cin>>floor>>room>>guest;
     int result;
        if(guest%floor==0){
            result=floor*100+(guest/floor);
        } else{
            result=(guest%floor)*100+(guest/floor)+1;
        }
        cout<<result<<'\n';
    }
    return 0;
}