#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=1e9;//10억
int n;
int check[4];//사칙연산
int num[11];
int max_num = -INF;
int min_num = INF;
void backtrack(int count, int val){
    //n-1개의 피연산자를 다 뽑음 , 종류시킨다.
    if(count==n-1){
        max_num=max(max_num,val);
        min_num= min(min_num,val);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (check[i] == 0) {
            continue;//사용할연산자가 없음
        }
        check[i]--;
        int sum = 0;
        int next=num[count + 1];
        if(i==0){
            sum =val +next;
        }
        else if(i==1){
            sum =val -next;
        }
        else if(i==2){
            sum =val *next;
        }
        else if(i==3){
            sum=val/next;
        }

        // 다음 연산자
        backtrack(count + 1, sum);

        //반납
        check[i]++;
    }
}
int main() {

    //연산
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> check[i];
    }
    // 연산
    backtrack(0, num[0]);

    // 출력
    cout << max_num << '\n' << min_num;

    return 0;
}