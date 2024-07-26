#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

int main()
{
    int N, sum = 0;
    cin >> N;
    vector<int> v(N);
    unordered_map<int, int> freq;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        sum += v[i];
        freq[v[i]]++;
    }

    sort(v.begin(), v.end());

    int size = v.size();

    int mean = round((double)sum / size);

    int center = v[size / 2];

    vector<pair<int, int>> tmp(freq.begin(), freq.end());
    sort(tmp.begin(), tmp.end(), [](auto const& l, auto const& r)
    {
        return l.second != r.second ? l.second > r.second : l.first < r.first;
    });

    int fre = tmp[0].first;

    if (tmp.size() > 1 && tmp[0].second == tmp[1].second)
        fre = tmp[1].first;

    int range = v[size - 1] - v[0];

    std::cout << mean << '\n' << center << '\n' << fre << '\n' << range << '\n';
}