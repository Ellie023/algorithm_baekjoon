#include <vector>
#include <iostream>

using namespace std;

int result(int n, int k, vector<int>& arr){
    int left =0, right =0;
    int Max=1;
    vector<int> check(100001,0);
    while (left<=right && right < n){

        if(check[arr[right]]<k){
            check[arr[right]]++;
            right++;
            Max=max(Max,right-left);
        } else{
            check[arr[left]]--;
            left++;
        }
    }
    return Max;
}

int main() {

    int n,k;

    cin>>n>>k;

    vector<int> arr(n,0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<result(n,k,arr);
    return 0;

}