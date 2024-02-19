#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> team[12];
    vector<long long> a(12,0);
    int n,k;
    cin>>n>>k;
    for(int j=0; j<k; j++){
        for(int i=0; i<n; i++){
            int input,score;
            cin>>input>>score;
            team[input].push(score);
            }
    }
    long long sum=0;
    for (int year = 0; year < k; year++) {
        for (int i = 1; i <= 11; i++) {
            if (!team[i].empty()) {
                if(a[i]==0){
                    a[i] = team[i].top()-1;
                    team[i].pop(); // 선택된 선수는 우선순위 큐에서 제거
                }
                else{
                    if(a[i] < team[i].top() && team[i].top() - 1 > 0){
                        a[i]=team[i].top()-1;
                        team[i].pop();
                    }
                }
            }

        }
    }
    for(int i=1; i<=11; i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}