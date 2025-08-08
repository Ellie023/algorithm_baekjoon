#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long long cross_sum = 0;
    for (int i = 0; i < N; ++i) {
        long long x1 = points[i].first;
        long long y1 = points[i].second;
        long long x2 = points[(i + 1) % N].first;
        long long y2 = points[(i + 1) % N].second;

        cross_sum += (x1 * y2) - (x2 * y1);
    }

    double area = fabs(cross_sum) / 2.0;

    // 소수점 첫째 자리까지 출력 (둘째 자리에서 반올림)
    cout << fixed << setprecision(1) << area << '\n';

    return 0;
}
