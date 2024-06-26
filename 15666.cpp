#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int n,m;
vector<int> ans,check;
void bracking(int cnt){
    if(cnt==m){
        for(int i=0; i<check.size(); i++){
            cout<<check[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    int num=-2;
    for(int i=0; i<n; i++){
        if(ans[i]==num){
            continue;
        }
        num=ans[i];
        check.push_back(num);
        bracking(cnt+1);

        check.pop_back();//반납

    }
    return;
}
int main() {
    //입력
    cin>>n>>m;
    for(int input,i=0; i<n; i++){
        cin>>input;
        ans.push_back(input);
    }
    sort(ans.begin(),ans.end());
    bracking(0);
    return 0;
}