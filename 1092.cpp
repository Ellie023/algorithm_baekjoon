#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n,m;
    int max, weight;
    int ans =0;
    vector<int> cranes;
    vector<int> boxes;

    //입력
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>max;
        cranes.push_back(max);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>weight;
        boxes.push_back(weight);
    }
    //내림차순으로 정렬, 큰 수가 앞으로 오게
    sort(cranes.begin(),cranes.end(),greater<int>());
    sort(boxes.begin(),boxes.end(),greater<int>());
    if(boxes[0]>cranes[0]){//무게가 가장 무거운 박스를 못 들면 -1 출력 종료
        cout<<"-1";
        return 0;
    }
    while(!boxes.empty()){
        ans++;
        for(int i =0; i<cranes.size(); i++){
            for(int j=0; j<boxes.size(); j++){
                if(cranes[i]>=boxes[j]){
                    boxes.erase(boxes.begin()+j);
                    break;
                }
            }
        }
    }

    cout<<ans;


    return 0;
}