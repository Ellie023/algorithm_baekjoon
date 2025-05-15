#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin>>N;

    int max_dp[3]={0}, min_dp[3]={0};
    int temp_max[3]={0}, temp_min[3];

    for(int i=0; i<N; i++){
        int a,b,c;
        cin>>a>>b>>c;

        if(i==0){
            max_dp[0] = min_dp[0] = a;
            max_dp[1] = min_dp[1] = b;
            max_dp[2] = min_dp[2] = c;
        }
        else{
            temp_max[0] = max(max_dp[0], max_dp[1]) + a;
            temp_max[1] = max({max_dp[0], max_dp[1], max_dp[2]}) + b;
            temp_max[2] = max(max_dp[1], max_dp[2]) + c;

            // min 계산
            temp_min[0] = min(min_dp[0], min_dp[1]) + a;
            temp_min[1] = min({min_dp[0], min_dp[1], min_dp[2]}) + b;
            temp_min[2] = min(min_dp[1], min_dp[2]) + c;
            // 현재 줄로 업데이트
            for (int j = 0; j < 3; ++j) {
                max_dp[j] = temp_max[j];
                min_dp[j] = temp_min[j];
            }

        }
    }
    int max_score = max({max_dp[0], max_dp[1], max_dp[2]});
    int min_score = min({min_dp[0], min_dp[1], min_dp[2]});
    cout <<max_score<<' '<<min_score << endl;
    return 0;
}