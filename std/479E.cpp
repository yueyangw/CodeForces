#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int M = 1000000007;

struct Solution {
    int N, A, B, K;
    vector<int> G;

    void Solve() {
        scanf("%d%d%d%d", &N, &A, &B, &K);
        G.resize(N + 1);
        for (int i = 1; i <= N; ++i) G[i] = 1;
        G[B] = 0;
        for (int i = 1; i <= N; ++i) G[i] += G[i - 1];
        for (int i = 0; i < K; ++i) {
            vector<int> GNew(N + 1);
            for (int j = 1; j <= N; ++j) {
                int d1 = min(j + abs(j - B) - 1, N);
                int d2 = max(j - abs(j - B), 0);
                int part1 = (G[d1] + M - G[d2]) % M;
                int part2 = (G[j - 1] + M - G[j]) % M;
                GNew[j] = (GNew[j - 1] + (part1 + part2) % M) % M;
            }
            swap(G, GNew);
        }
        printf("%d\n", (G[A] + M - G[A - 1]) % M);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
