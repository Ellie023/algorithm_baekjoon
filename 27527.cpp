#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    int n,m;
    cin>>n>>m;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    float over=0;
    bool flag= false;

    unordered_map<int, int> number;
    if ((9 * m) % 10 == 0) {
        over = (9 * m) / 10;
    }
    else {
        over = (9 * m) / 10;
        over++;
    }
    int start=0;
    int end=m-1;
    int target;
        for(int i=0; i<m; i++) {
            target = A[i];
            number[target]++;
            if(number[target]==over){
                flag=true;
            }
        }
    for (int i = m; i < n; i++) {
        int Prev = A[i - m];
        int Next = A[i];
        number[Prev]--;
        number[Next]++;
        if (number[Next] == over) {
            flag = true;
        }
    }
    if(flag){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}