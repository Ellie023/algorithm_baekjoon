#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        string P;
        deque<int> D;
        string arr;
        cin >> P;
        int n;
        cin >> n;
        cin >> arr;
        if(n>0){
            string substr =arr.substr(1,arr.size()-2);
            stringstream ss(substr);
            string num;
            while(getline(ss,num,',')){
                D.push_back(stoi(num));
            }
        }
        bool reversed = false;  // '뒤집힘' 상태 관리 플래그
        bool errorFlag = false; // 에러 발생 여부
        for(char c: P){
            if(c=='R'){
                reversed =!reversed;
            }
            else if(c == 'D') {
                // 덱이 비어 있으면 즉시 에러
                if(D.empty()) {
                    cout << "error\n";
                    errorFlag = true;
                    break;
                }
                else {
                    // reversed 여부에 따라 pop_front() 또는 pop_back()
                    if(!reversed) {
                        D.pop_front();
                    } else {
                        D.pop_back();
                    }
                }
            }
        }
        // 에러가 발생하지 않았다면 최종 결과 출력
        if(!errorFlag) {
            if(!reversed) {
                // 뒤집히지 않은 상태 그대로 출력
                cout << "[";
                for(int i = 0; i < (int)D.size(); i++) {
                    cout << D[i];
                    if(i < (int)D.size() - 1) {
                        cout << ",";
                    }
                }
                cout << "]\n";
            } else {
                // 뒤집힌 상태이므로 뒤에서부터 출력
                cout << "[";
                for(int i = D.size() - 1; i >= 0; i--) {
                    cout << D[i];
                    if(i > 0) {
                        cout << ",";
                    }
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}