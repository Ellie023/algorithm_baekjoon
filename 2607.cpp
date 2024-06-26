#include <iostream>
#include "vector"
#include <algorithm>

using namespace std;
int countF(string word, vector<int> &arr){
    vector<int> a(26, 0);
    int count=0;
    for (int i = 0; i < word.length(); i++) {
        a[word[i] - 'A']++;//알파벳 개수 세기
    }
    for (int i = 0; i < 26; i++) {
        count += abs(arr[i] - a[i]);//두 단어에서 다른 알파벳의 개수
    }
    return count;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int n;
    int ans=0;
    string original;
    //입력
    cin>>n;
    cin>>original;
    vector<int> arr(26,0);//알파벳 구성

    for (int i = 0; i <original.length(); i++) {
        arr[original[i] - 'A']++;//알파벳 개수 세기
    }
    for(int i=0; i<n-1; i++){
        string word;
        cin>>word;
        //연산
        int count = countF(word, arr);
        // 비슷한 단어
        if (count == 0 || count == 1 || count == 2 && original.length() == word.length()) {
            ans++;
        }
    }
    //출력
    cout << ans;

    return 0;
}