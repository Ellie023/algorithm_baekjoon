#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int m,n;
    cin>>n>>m;
    int max=0;
    vector<int> tree(n,0);
    for(int i=0; i<n; i++){
        cin>>tree[i];
    }
    sort(tree.begin(),tree.end());
    long long low=0;
    long long high=tree[n-1];
//10 20 15
    while(low<=high){
        long long sum=0;
        long long cut=(low+high)/2;
        for(int i=0; i<n; i++) {
            if (tree[i] - cut > 0) {
                sum += tree[i] - cut;
            }
        } //15 17 20
            if(sum>=m){
                max=cut;
                low=cut+1;
            }//9 11
            else{
                high=cut-1;
            }
        }


    cout<<max;
    return 0;
}