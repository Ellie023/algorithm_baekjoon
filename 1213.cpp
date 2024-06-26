#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

void countalpa(string word , vector<int> &alpha){//각 알파벳의 개수 세기
    for(int i=0; i<word.length(); i++){
        alpha[word[i]-'A']++;
    }
}
bool canNot(vector<int> alpha){
    int cnt=0;
    for(int i=0; i<26; i++) {
        if (alpha[i] % 2 == 1)
            cnt++;
    }
        return cnt > 1;//홀수가 2개 이상

}
string make_palin(vector<int> alpha){
    string palind;
    for(int i = 0; i < 26; i++) {//a~z까지 개수의 반만 차레대로 팰란드에 더함
        for (int j = 0; j < alpha[i] / 2; j++) {
            palind += i + 'A';
        }
    }
    for(int i = 0; i < 26; i++) {
        if (alpha[i] % 2) {//팰란드의 개수가 홀수라면 남은 한 개가 가운데에 와야 함
            palind += i + 'A';
        }
    }
    for(int i = 25; i >= 0; i--) {
        for (int j = 0; j < alpha[i] / 2; j++) {//z-a까지 개수의 반만 차레대로 팰란드에 더함
            palind += i + 'A';
        }
    }
    return palind;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string word;

    //입력
    cin>>word;
    vector<int> alpha(26,0);
    countalpa(word,alpha);//각 알파벳의 개수 세기
    if(canNot(alpha)){
        cout<<"I'm Sorry Hansoo";//알파벳의 개수가 홀수인 알파벳이 2개 이상
        return 0;
    }
    string palind= make_palin(alpha);//펠린드롬 만들기

    cout<<palind<<'\n';//출력


    return 0;
}