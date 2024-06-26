#include <iostream>
#include <vector>
#include "algorithm"
using namespace
std;

int main() {

    int n,s=0;
    cin>>n;
    vector<int> a(n,0), b(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // A 입력 받기
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i]; // B 입력 받기
    }
    sort(a.begin(), a.end()); // A 오름차순 정렬
    sort(b.begin(), b.end(), greater<>()); // B 내림차순 정렬
    for (int i = 0; i < n; i++) {
        s += a[i] * b[i]; // 배열 A, B의 각 원소의 곱 더하기
    }
    // 출력
    cout << s;
    return 0;
}