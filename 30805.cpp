#include <iostream>
#include <algorithm>
using namespace std;

#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

struct Elem {
    int val, idx;
};

bool cmp(const Elem& a, const Elem& b) {
    return (a.val != b.val) ? (a.val > b.val) : (a.idx < b.idx);
}

int main() {
    FASTIO;

    int n, m;
    cin >> n;
    Elem A[100];
    for (int i = 0; i < n; ++i) {
        cin >> A[i].val;
        A[i].idx = i;
    }

    cin >> m;
    Elem B[100];
    for (int i = 0; i < m; ++i) {
        cin >> B[i].val;
        B[i].idx = i;
    }

    sort(A, A + n, cmp);
    sort(B, B + m, cmp);

    int ans[100], ansLen = 0;
    int idxA = 0, idxB = 0, limitA = 0, limitB = 0;

    while (idxA < n && idxB < m) {
        if (A[idxA].val == B[idxB].val) {
            if (A[idxA].idx < limitA) {
                ++idxA;
            } else if (B[idxB].idx < limitB) {
                ++idxB;
            } else {
                limitA = A[idxA].idx;
                limitB = B[idxB].idx;
                ans[ansLen++] = A[idxA].val;
                ++idxA;
                ++idxB;
            }
        } else if (A[idxA].val > B[idxB].val) {
            ++idxA;
        } else {
            ++idxB;
        }
    }

    cout << ansLen << '\n';
    for (int i = 0; i < ansLen; ++i) {
        cout << ans[i];
        if (i + 1 < ansLen) cout << ' ';
    }
    cout << '\n';

    return 0;
}
