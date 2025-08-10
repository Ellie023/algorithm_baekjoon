#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    int L = 0, R = N - 1;
    long long bestSum = LLONG_MAX;
    long long ansL = a[L], ansR = a[R];

    while (L < R) {
        long long s = a[L] + a[R];
        if (llabs(s) < llabs(bestSum)) {
            bestSum = s;
            ansL = a[L];
            ansR = a[R];
            if (bestSum == 0) break; // 더 볼 필요 없음
        }
        if (s < 0) ++L;     // 합을 키우기 위해 왼쪽을 오른쪽으로
        else --R;           // 합을 줄이기 위해 오른쪽을 왼쪽으로
    }

    cout << ansL << ' ' << ansR << '\n';
    return 0;
}
