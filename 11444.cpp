#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const long long MOD=1000000007;

vector<vector<long long>> multiply(const vector<vector<long long>>& a,const vector<vector<long long>> &b) {
    vector<vector<long long>> result(2, vector<long long>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<long long>> power(vector<vector<long long>> matrix,long long n){
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    while(n>0){
        if (n % 2 == 1) result = multiply(result, matrix);
        matrix = multiply(matrix, matrix);
        n /= 2;
    }
    return result;
}

int main() {

    long long n;
    cin>>n;

    if(n==0){
        cout<<0<<'\n';
        return 0;
    }

    vector<vector<long long>> base ={{1,1},{1,0}};
    vector<vector<long long>> result =power(base,n-1);

    cout<<result[0][0]<<'\n';
    return 0;
}