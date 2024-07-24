#include <iostream>
#include <queue>

using namespace std;

int main() {

    int count=0;
    int test;
    cin>>test;
    int n,m,input;
    for(int i=0; i<test; i++) {
        count = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int j = 0; j < n; j++) {
            cin >> input;
            q.push({j, input});
            pq.push(input);
        }
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                ++count;
                if (index == m) {
                    cout << count << endl;
                    break;
                }
            } else q.push({index, value});

        }
    }
    return 0;
}