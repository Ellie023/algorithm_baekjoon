    #include <iostream>
    #include "vector"
    #include "queue"
    using namespace std;

    int main() {

        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n;
        cin>>n;//입력

        priority_queue<int,vector<int>,greater<int>> heap;//내림차순으로 heap
        for(int i=0; i<n*n; i++){//n*n 입력
            int x;
            cin>>x;
            heap.push(x);
            if(heap.size()>n){//heap에 5개의 숫자만 들어가게 한다.
                heap.pop();//작은 거 pop
            }
        }
        cout<<heap.top();
        return 0;
    }