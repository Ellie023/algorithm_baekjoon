    #include <iostream>
    #include <queue>

    using namespace std;
struct cmp{
    bool operator()(const int& x1, const int& x2){
        if(abs(x1)!=abs(x2)){
            return abs(x1)>abs(x2);
        }
        return x1>x2;
    }
};

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        int n,x;
        priority_queue<int,vector<int>,cmp> max_heap;

        cin>>n;

        while(n--){
            cin>>x;
            if(x==0){
                if(max_heap.empty()){
                    cout<<"0\n";
                }
                else{
                    cout<<max_heap.top()<<'\n';
                    max_heap.pop();
                }
            }
            else{
                max_heap.push(x);
            }
        }
        return 0;
    }