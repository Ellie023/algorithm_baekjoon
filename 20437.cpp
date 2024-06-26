#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> ci;
const int ALPHA_NUM=26;
ci game(string w, int k){
    vector<vector<int>> char_idx(26);
    int min_len=w.size();
    int max_len=-1;
    for(int i=0; i<w.size(); i++){
        char_idx[w[i]-'a'].push_back(i);
    }
    for(int i=0; i<26; i++){
        int cnt=char_idx[i].size();

        if(cnt<k){
            continue;
        }
        int left=0,right=k-1;
        while (right<cnt){
            int tmp_len = char_idx[i][right] - char_idx[i][left] + 1; // 처음과 끝이 해당 알파벳인 문자열의 길이
            min_len = min(min_len, tmp_len);
            max_len = max(max_len, tmp_len);
            left++; // 윈도우 이동
            right++;
        }
    }
    return {min_len, max_len};
}
int main() {
    int t,k;
    cin>>t;
    string w;
    while (t--){
        cin>>w>>k;
        pair<int,int> ans=game(w,k);

        if(ans.second==-1){
            cout<<-1<<'\n';
        }
        else{
            cout<<ans.first<<" "<<ans.second;
        }
    }
    return 0;
}