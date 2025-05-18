#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int city[50][50];

// 치킨 거리 계산 함수
int calculateChickenDistance(const vector<pair<int, int>>& selected) {
    int total = 0;
    for (auto& h : houses) {
        int minDist = INT_MAX;
        for (auto& c : selected) {
            int dist = abs(h.first - c.first) + abs(h.second - c.second);
            minDist = min(minDist, dist);
        }
        total += minDist;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    // 도시 정보 입력 및 집, 치킨집 좌표 저장
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                houses.emplace_back(i, j);
            } else if (city[i][j] == 2) {
                chickens.emplace_back(i, j);
            }
        }
    }

    vector<int> select(chickens.size(), 0);
    fill(select.end() - M, select.end(), 1); // 조합을 위한 선택 마스크

    int answer = INT_MAX;

    do {
        vector<pair<int, int>> selectedChickens;
        for (int i = 0; i < select.size(); ++i) {
            if (select[i]) {
                selectedChickens.push_back(chickens[i]);
            }
        }

        int dist = calculateChickenDistance(selectedChickens);
        answer = min(answer, dist);

    } while (next_permutation(select.begin(), select.end()));

    cout << answer << '\n';

    return 0;
}
