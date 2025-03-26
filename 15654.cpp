#include <iostream>
#include <algorithm>

using namespace std;
int N,M;
int num[10];
int ans[10];
int visited[10]={0};
void Back(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < N; i++) {
            if (visited[i] == 0) {
                ans[count] = num[i];
                visited[i] = 1;
                Back(count + 1);
                visited[i] = 0;

            }
        }
    }
}

int main() {

    cin>>N>>M;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);
    Back(0);
    return 0;
}