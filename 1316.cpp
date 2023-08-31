#include <iostream>
#include "string"
#include "set"
#include "vector"
using namespace std;


int main() {


    int n;
    string s;

    cin>>n; //단어의 개수 입력
    int count=0;

    while(n--){
        set<char> set;
        cin>>s;//단어 입력
        set.insert(s[0]);
        count++;// 맞는 단어라고 가정하기
        for(int i=0; i<s.length()-1; i++){
            if(s[i] !=s[i+1]){//연속의 문자가 아니면
                if(set.find(s[i+1])==set.end()){//set에서 문자가 있는 지 탐색
                    set.insert(s[i+1]);//없으면 set에 넣기
                }
                else{
                    count--;//가정이므로 count는 지운다,set에 문자가 있으면 다음 단어를 검사
                    break;
                }
            }



        }
        set.clear();
    }
    cout<<count;//출력
    return 0;
}