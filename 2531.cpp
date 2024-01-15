#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt=0;
    int n,d,k,c;

    cin>>n>>d>>k>>c;
    vector<int> sushi(n+1,0);
    vector<int> kind(d+1,0);
    for(int i=0; i<n; i++){
        cin>>sushi[i];
    }
    kind[c]++;//쿠폰
    cnt++;
    for(int i=0; i<k; i++){
        kind[sushi[i]]++;
        if(kind[sushi[i]]==1) {
            cnt++;
        }
    }


    int left=0,right=k-1,result=0;
    while (left<n){

        kind[sushi[left]]--;
        if(kind[sushi[left++]]==0) cnt--;
        right = (right+1)%n;
        kind[sushi[right]]++;
        if(kind[sushi[right]]==1) cnt++;
        result=max(result,cnt);
    }

    cout<<result;
    return 0;
}