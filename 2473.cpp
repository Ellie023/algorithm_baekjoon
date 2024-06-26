#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ci;
const long long INF=3 * 1e9 + 1;
tuple<int,int,int> findLiquid(vector<long long> liquid){

    long long value=INF;
    tuple<int,int,int> ans;
    for (int i = 0; i < liquid.size() - 2; i++) {
        int left = i + 1;
        int right = liquid.size() - 1;

        while (left < right) {
            long long mix = liquid[left] + liquid[right] + liquid[i];

            if (abs(mix) < value) {
                value = abs(mix);
                ans = {liquid[i],liquid[left], liquid[right]};
            }
            if (mix < 0) {
                left++;
            } else if(mix>0){
                right--;
            }
            else{
                return ans;
            }
        }
    }
    return ans;
}
int main() {

    int n;

    cin>>n;

    vector<long long> liquid;
    liquid.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>liquid[i];
    }

    sort(liquid.begin(),liquid.end());
    tuple<int,int,int> ans= findLiquid(liquid);
    cout<<get<0>(ans)<<" "<<get<1>(ans)<<" "<<get<2>(ans);
    return 0;
}