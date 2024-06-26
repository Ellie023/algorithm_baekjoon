#include <iostream>
#include "vector"

using namespace std;

long long sorted[500001];
long long count=0;
void merge(vector<long long> &arr,int l, int m, int r){
    int i=l;
    int j=m+1;
    int k=l;

    while (i<=m&&j<=r){
        if(arr[i]<=arr[j]){
            sorted[k]=arr[i];
            i++;
        }
        else{//순서 바꾸기
            sorted[k]=arr[j];
            j++;
            count += m- i + 1;//바꿀 것
        }
        k++;
    }
    if(i>m){//남아있는 수들도 붙여넣기
        for(int t=j; t<=r; t++){
            sorted[k]=arr[t];
            k++;
        }
    }
    else{
        for(int t=i; t<=m; t++){
            sorted[k]=arr[t];
            k++;
        }
    }
    for(int t=l; t<=r; t++){//정렬된 배열 옮겨담기
        arr[t]=sorted[t];
    }

}

void merge_sort(vector<long long> &arr,int left, int right){
    if(left<right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<long long>arr;
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);
    }
    merge_sort(arr,0,n-1);
    cout<<count;
    return 0;
}