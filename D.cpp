#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 998244353;

int main() {
    int W, H, K, T;
    cin >> W >> H >> K >> T;

    // Initialize set to store virus positions
    set<pair<int, int>> viruses;

    // Input virus positions
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        viruses.insert({x, y});
    }

    // Simulate virus movement for T seconds
    for (int t = 0; t < T; ++t) {
        set<pair<int, int>> newViruses;

        // Update virus positions
        for (auto virus : viruses) {
            int x = virus.first;
            int y = virus.second;
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 1 && nx <= W && ny >= 1 && ny <= H) {
                        newViruses.insert({nx, ny});
                    }
                }
            }
        }

        // Update virus set
        viruses = newViruses;
    }

    // Print the number of different virus distributions modulo MOD
    cout << viruses.size() % MOD << endl;

    return 0;
}
