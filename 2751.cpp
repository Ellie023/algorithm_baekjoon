#include <iostream>
#include <vector>

using namespace std;

vector<int> sorted;

void merge(vector<int>& arr , int left,int mid,int right){
    int f=left, j=mid+1,k=left;
    while (f<=mid&&j<=right){
        if(arr[f]<arr[j])
            sorted[k++]=arr[f++];
        else
            sorted[k++]=arr[j++];
    }
    while(f<=mid){
        sorted[k++]=arr[f++];

    }
    while(j<=right) {
        sorted[k++] = arr[j++];
    }
    for(int l=left; l<=right; l++){
        arr[l]=sorted[l];
    }
}
void mergesort(vector<int>& arr ,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    sorted.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<'\n';
    }
    return 0;

}
