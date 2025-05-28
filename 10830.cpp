#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;
using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<long long>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;

    return result;
}
Matrix power(Matrix A, long long exp) {
    int n = A.size();
    Matrix result(n, vector<long long>(n, 0));

    // 단위 행렬 초기화
    for (int i = 0; i < n; ++i)
        result[i][i] = 1;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = multiply(result, A);
        A = multiply(A, A);
        exp /= 2;
    }
    return result;
}
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  long long b;
  cin>>N>> b;

  Matrix A(N,vector<long long>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
    Matrix result = power(A, b);

    // 출력
    for (const auto& row : result) {
        for (long long x : row)
            cout << x % MOD << " ";
        cout << '\n';
    }
    return 0;
}