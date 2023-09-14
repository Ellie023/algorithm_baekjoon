#include <iostream>
#include "vector"
using namespace std;

int originPrime(int n,int k) {
    vector<bool> is_prime(n + 1, true);

    int cnt = 0;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i])
            continue;
        for (int j = i; j <= n; j += i) {
            if (!is_prime[j])
                continue;
            if (++cnt == k)
                return j;
            is_prime[j] = false;
        }
    }
    return -1;
}


int main() {


        int n,k;
        cin>>n>>k;
        cout<<originPrime(n,k);
    return 0;
}