#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    queue<int> q;
    string command;

    while (N--) {
        cin >> command;
        if (command == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (command == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (command == "size") {
            cout << q.size() << '\n';
        } else if (command == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if (command == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        } else if (command == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }

    return 0;
}
