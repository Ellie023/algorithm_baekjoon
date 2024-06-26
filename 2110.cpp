#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cntRouter(int dist, vector<int>& router) {

    int cnt = 1;
    int cur = router[0];

    for (int i = 1; i < router.size(); i++) {
        if (router[i] - cur >= dist) { // 가장 가까운 집과의 거리가 dist 이상이라면
            cnt++; // 공유기 설치
            cur = router[i];
        }
    }
    return cnt; // 설치된 공유기의 수
}

int binarySearch(int left, int right, int key, vector<int>& house){
    while(left<=right){
        int mid = (left + right) / 2;
        int installed = cntRouter(mid, house);
        if (installed >= key) { // mid의 거리로는 target 개수 이상의 공유기를 설치할 수 있음 -> 거리를 늘려보자
            left = mid + 1;
        }
        else { // mid의 거리로는 target만큼의 공유기 설치할 수 없음 -> 거리를 줄여야 한다
            right = mid - 1;
        }
    }
    return left - 1; //upper bound값에서 1을 뺌
    }


int main(){
    int n,c;

    cin>>n>>c;
    vector<int> house(n,0);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    // 연산
    sort(house.begin(), house.end());
    cout<<binarySearch(1,house[n-1]-house[0],c,house);
    return 0;
}