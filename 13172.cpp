#include <iostream>
#include <numeric> // gcd
using namespace std;

typedef long long ll;
const ll MOD = 1'000'000'007;

// 모듈러 제곱 (페르마의 소정리에 기반한 b^(MOD-2) 계산)
ll mod_pow(ll base, ll exp) {
    ll result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    ll total = 0;

    for (int i = 0; i < M; ++i) {
        ll N, S;
        cin >> N >> S;

        // 기약분수로 만들기
        ll g = gcd(S, N);
        S /= g;
        N /= g;

        // 기대값을 모듈러 상에서 더하기: (S * N^{-1}) % MOD
        ll inv = mod_pow(N, MOD - 2);
        ll val = S * inv % MOD;
        total = (total + val) % MOD;
    }

    cout << total << '\n';
    return 0;
}
