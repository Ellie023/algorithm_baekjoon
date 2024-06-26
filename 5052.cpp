#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<string> A(n);
        map<string, bool> book;

        for (int j = 0; j < n; j++) {
            cin >> A[j];
            book[A[j]] = true;
        }

        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (!flag) break;

            string temp = "";
            for (int k = 0; k < A[j].length(); k++) {
                temp += A[j][k];
                if (book[temp] && temp != A[j]) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
