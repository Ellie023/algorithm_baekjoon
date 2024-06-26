#include <iostream>
#include <vector>

using namespace std;
int binarySearch(int n, vector<int> &bar){
    int left=1;//최소길이
    int right=1000000000;//최대길이

    int result=0;
    while (left<=right){
        int cnt=0;
        int mid = (left + right) / 2;//길이를 정해서
        for (int i = 0; i < bar.size(); i++) {
            cnt += bar[i] / mid;//똑같이 자른 다음 나눠줌
        }
        if (cnt >= n) {//조각의 개수가 조카 수보다 더 크면
            left = mid + 1;
            result = mid;
        }
        else{//조각의 게수가 더 작으면
            right = mid - 1;
        }
    }
    return result;

}
int main() {

    int n,snack;//학생 수, 과자 수


    //입력
    cin>>n>>snack;

    vector<int> bar(snack);

    for (int i = 0; i < snack; i++) {
        cin >> bar[i];//막대과자 길이
    }

    cout << binarySearch(n, bar);
    return 0;
}