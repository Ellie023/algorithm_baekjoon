#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin>>n;
    if(n==0){
        cout<<0;
    }
    else {
        vector<int> solved(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> solved[i];
        }
        sort(solved.begin(), solved.end());

        float a = int(n * 0.15 + 0.5);

        int sum = 0;

        int j = 0;
        for (int i = a; i < n - a; i++) {
            sum += solved[i];
            j++;
        }
        float result = ::floor((float) sum / j + 0.5);
        cout << result;
    }


    return 0;
}