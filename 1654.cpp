#include <iostream>

using namespace std;

long long arr[10001];
int k,n;
int binary_search(int max){
    long long left=1, right=max;
    long long ans;
    while (left<=right) {
        long long mid = (left + right) / 2;
        long long count = 0;
        for (int i = 0; i < k; i++) {
            count += (arr[i] / mid);
        }
        if (count >= n) {
            left = mid + 1;
            ans=mid;
        } else {
            right = mid - 1;
        }
    }
        return ans;
}
int main() {

    int max=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>k>>n;
    for(int i=0; i<k; i++){
        cin>>arr[i];
        if(max<arr[i]){
            max=arr[i];
        }
    }

    cout<<binary_search(max);

    return 0;
}