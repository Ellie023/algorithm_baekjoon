#include <iostream>

using namespace std;

int cnt=0;

int fibonacci(int n) {
    cnt++;//       호출
    if (n < 2) {
        return n;
    }

    return fibonacci(n-2) + fibonacci(n-1);
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int dp[51];

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = (1 + dp[i-2] + dp[i-1])%1000000007;
    }

    cout << dp[n];
    return 0;
}