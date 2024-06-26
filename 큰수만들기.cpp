#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int binarySearch(int key, vector<int>& card, int n) {

    int left = 0;
    int right = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (key == card[mid]) {
            return 1;
        }
        if (card[mid] < key) {
            left = mid + 1;
        }
        else {right = mid - 1;}
    }
    return 0;
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);
    // 입력
    int n, m, key;
    cin >> n;
    vector<int> card(n);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }
    sort(card.begin(), card.end()); //오름차 순으로 정렬

    cin >> m;
    while (m--) {
        cin >> key;
        cout << binarySearch(key, card, n) << ' ';
    }
    return 0;
}