#include <iostream>
#include "vector"

using namespace std;
typedef pair<int, char> ic;
string printWheel(int n, int index, vector<char>& wheel) {
    string ans = "";
    //바퀴를 돌릴 때와 반대방향으로 출력
    for (int i = index + n; i > index; i--) {
        ans += wheel[i % n];
    }
    return ans;
}

string makeWheel(int n, int k, vector<ic>& record) {

    vector<bool> is_available(26, false);
    int cnt=0;
    vector<char> lucky(n, '?');
    for (int i = 0; i < k; i++) {
        int s=record[i].first;
        int c=record[i].second;

        cnt = (cnt + s) % n;

        if (lucky[cnt] == c) {
            continue;
        }
        if (lucky[cnt] != '?' || is_available[c - 'A']) {
            return "!";
        }
        lucky[cnt] = c;
        is_available[c - 'A'] = true;

    }
    return printWheel(n, cnt, lucky);
}
int main() {
    int n,k;
    cin>>n>>k;

    vector<ic> record(k);
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }
    cout << makeWheel(n, k, record);

    return 0;
}