#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cntRouter(int dist, vector<int>& house){
    int cnt=1;
    int cur=house[0];
    for(int i=1; i<house.size(); i++){
        if(house[i]-cur>=dist){
            cnt++;
            cur=house[i];
        }
    }
    return cnt;
}
int binarysearch(int left,int right, int target, vector<int> &house){
    while(left<=right){
        int mid =(left+right)/2;
        int installed= cntRouter(mid,house);
        if(installed>=target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left-1;
}
int main() {

    int n,c;
    cin>>n>>c;
    vector<int> house(n,0);

    for(int i=0; i<n; i++){
        cin>>house[i];
    }    sort(house.begin(),house.end());
    cout<<binarysearch(1,house[n-1]-house[0],c,house);
    return 0;
}