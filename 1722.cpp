#include <iostream>

using namespace std;

static int N,Q;
static long F[21],S[21];
static bool visited[21]{false};

int main() {

    cin>>N>>Q;
    F[0]=1;
    for(int i=1; i<=N; i++){
        F[i]=F[i-1]*i;
    }
    if(Q==1){
        long k;
        cin>>k;

        for(int i=1; i<=N; i++){
            for(int j=1, cnt=1; j<=N; j++){
                if(visited[j]){
                    continue;
                }
                if(k<=cnt*F[N-i]){
                    k-=(cnt-1)*F[N-i];
                    S[i]=j;
                    visited[j]=true;
                    break;
                }
                cnt++;
            }
        }
        for(int i=1; i<=N; i++){
            cout<<S[i]<<" ";
        }
    }
    else{
        long k=1;
        for(int i=1; i<=N; i++){
            cin>>S[i];
            long cnt=0;

            for(int j=1; j<S[i]; j++){
                if(visited[j]==false){
                    cnt++;
                }
            }
            k+=cnt*F[N-i];
            visited[S[i]]=true;
        }
        cout<<k<<"\n";
    }

    return 0;
}