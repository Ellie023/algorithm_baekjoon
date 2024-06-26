#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<double> tep_l(n,0),sum(n,0);
    cin>>tep_l[0];
    sum[0]=tep_l[0];
    for(int i=1; i<n; i++){
        cin>>tep_l[i];
        sum[i]=sum[i-1]+tep_l[i];
    }
    int screen,q;
    cin>>screen>>q;
   for(int i=0; i<q; i++){
      int a;
       cin>>a;
        double target=tep_l[a];
        double limit=(a==0)?0:sum[a-1];
        double r=sum[n-1]-sum[a];
        double limit_len=limit+target/2.0;
        double r_len=r+target/2.0;
       if (screen >= sum[n-1]) printf("%.2f\n", 0.0);
       else if (limit_len <= screen/ 2.0) printf("%.2f\n", 0.0);
       else if (r_len <= screen / 2.0)
           printf("%.2f\n", sum[n-1] - screen);
       else {
           printf("%.2f\n", limit_len - screen / 2.0);
       }
    }

    return 0;
}