#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<int> A(N,0);
    vector<char> resultV;

    stack<int> S;
    int num =1;
    bool result= true;
    for(int i=0; i<N; i++){
        int now;
        cin>>now;
        if(now>=num){
            while (now>=num){
                S.push(num);
                num++;
                resultV.push_back('+');
            }
            S.pop();
            resultV.push_back('-');
        }
        else {
            if (S.top() > now) {
                cout << "NO";
                return 0;
            }
            S.pop();
            resultV.push_back('-');

        }
    }
    for(int i=0; i<resultV.size(); i++){
        cout<<resultV[i]<<'\n';
    }
    return 0;
}