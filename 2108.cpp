#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    int n;
    unordered_map<int,int> freq;
    cin>>n;

    vector<int> v(n,0);
    vector<int> bin;
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
        freq[v[i]]++;
    }
    sort(v.begin(),v.end());
    cout<< round(sum/n)<<'\n'<<v[n/2]<<'\n';
    vector<pair<int, int>> tmp(freq.begin(), freq.end());
    sort(tmp.begin(), tmp.end(), [](auto const& l, auto const& r)
    {
        return l.second != r.second ? l.second > r.second : l.first < r.first;
    });

    int fre = tmp[0].first;

    if (tmp.size() > 1 && tmp[0].second == tmp[1].second)
        fre = tmp[1].first;
    cout<<fre<<'\n';
    cout<<v[n-1]-v[0]<<'\n';
    return 0;
}