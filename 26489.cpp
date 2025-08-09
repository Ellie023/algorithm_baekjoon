#include<iostream>

#include<string>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    string s;
    int res = 0;
    while (getline(cin, s)) {
        res++;
    }

    cout << res;

    return 0;
}