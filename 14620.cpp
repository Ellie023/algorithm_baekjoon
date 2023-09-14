 #include <iostream>
#include "vector"
#include "algorithm"
using namespace std;
 const int MAX = 200 * 15;
 int getScore(int r, int c, vector<vector<int>> price) {
     return price[r - 1][c] + price[r][c - 1] + price[r + 1][c] + price[r][c + 1] + price[r][c];
 }

int solution(int n,vector<vector<int>> &price){
    int ans=MAX;
    int r1,c1,r2,c2,r3,c3;

    n-=2;
    for(int i=0; i<n*n; i++){
        r1=i/n+1;
        c1=i%n+1;
        for(int j=0; j<n*n; j++){
            r2=j/n+1;
            c2=j%n+1;
            if(abs(r2-r1)+abs(c2-c1)<3){
                continue;
            }
            for(int k=0; k<n*n; k++){
                r3=k/n+1;
                c3=k%n+1;

                if(abs(r3-r1)+abs(c3-c1)<3) continue;
                if(abs(r3-r2)+abs(c3-c2)<3)continue;
                ans = min(ans, getScore(r1, c1, price) + getScore(r2, c2, price) + getScore(r3, c3, price));
            }

        }
    }
     return ans;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> price;
    price.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> price[i][j];
        }
    }
    cout << solution(n, price);
    return 0;
}