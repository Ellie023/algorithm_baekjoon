#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int level;
    vector<int> check;
    vector<pair<int,int>> question;
    for(int i=0; i<5; i++){
        cin>>level;
        check.push_back(level);
    }
    int k,t;
    while(n--){
        cin>>k>>t;
        question.push_back(make_pair(k,t));
    }
    int sum=0;
    int j=0;
    sort(question.begin(),question.end());

    for(int i=0; i<5; i++){
        vector<int> least;
        while (i+1==question[j].first){
            least.push_back(question[j].second);
            j++;
        }
        sort(least.begin(),least.end());
        int a=check[i];
        int l=0;
        int Min;
        while (a--){
            Min=least[l];
           sum+=Min;
            l++;
        }
        sum+=(Min-least[0]);
        sum+=60;
    }
    sum-=60;
    cout<<sum;
    return 0;
}