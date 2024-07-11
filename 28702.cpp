#include <iostream>

using namespace std;

int main() {


    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string input;
    int result;
    int plus=3;
    for(int i=0; i<3; i++) {
        cin >> input;
        if(input[input.length()-1]!='z'){
            result= stoi(input)+plus;
            break;
        }
        plus--;
    }
    if(result%15==0){
        cout<<"FizzBuzz";
    }
    else if(result%3==0){
        cout<<"Fizz";
    }
    else if(result%5==0){
        cout<<"Buzz";
    }
    else{
        cout<<result;
    }
    return 0;
}