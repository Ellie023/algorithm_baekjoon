#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// 주어진 수가 소수인지 판별하는 함수
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 주어진 수가 팰린드롬인지 판별하는 함수
bool isPalindrome(int n) {
    string original = to_string(n);
    string reversed = original;
    reverse(reversed.begin(), reversed.end());
    return original == reversed;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;

    // 주어진 수부터 시작하여 조건을 만족하는 수를 찾음
    while (true) {
        if (isPrime(n) && isPalindrome(n)) {
            cout << n << '\n';
            break;
        }
        ++n;
    }

    return 0;
}
