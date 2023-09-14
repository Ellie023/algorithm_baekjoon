    #include <iostream>

    using namespace std;
    typedef long long ll;
    const int MAX=60;
    pair<int,int> getpair(ll m){
        int x,y;
        for(int i=0; i<MAX; i++){
            if(m==((ll)i<<i)){
                return {i-1,i-1};
            }
        }
        for(x=0; x<MAX; x++){
            if(m&((ll)1<<x)){
                break;
            }
        }
        for(y=x+1; y<MAX; y++){
            if(m&((ll)1<<y)){
                break;
            }
        }
        return {x,y};
    }

    int main() {

        int n;
        ll m;
        cin>>n;
        while (n--){
            cin>>m;
            pair<int,int>ans=getpair(m);
            cout<<ans.first<<" "<<ans.second<<"\n";
        }

        return 0;
    }