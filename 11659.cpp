#include <iostream>
#include <vector>
using namespace std;
void calSum(int n, vector<int> &sum) {
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1]; // 첫번째 수부터 i번째 수까지의 누적 합
    }
}
int getPrefixSum(int i, int j, vector<int> &sum) {
    return sum[j] - sum[i - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, i, j;

    cin>>n>>m;
    vector<int> sum(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>sum[i];
    }

    calSum(n,sum);

    while(m--){
        cin>>i>>j;
        cout << getPrefixSum(i, j, sum) << "\n";
    }
    return 0;
}