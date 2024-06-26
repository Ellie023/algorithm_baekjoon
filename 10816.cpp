#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int lowerBound(int left, int right, int key, vector<int>& arr){
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>=key){
            right=mid-1;

        }
        else{
            left=mid+1;
        }
    }
    return left;
}
int upperBound(int left,int right, int key,vector<int>& arr){
    while (left<=right){
        int mid=(left+right)/2;
        if(arr[mid]<=key){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,input;


    //입력
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //이분 탐색을 하기 위해 정렬
    sort(arr.begin(), arr.end());
    cin>>m;

    while (m--) {
        cin >> input;
        //연산 & 출력
        cout << upperBound(0, n - 1, input, arr) - lowerBound(0, n - 1, input, arr) << ' ';
    }
    return 0;
}