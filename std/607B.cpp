#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

bool AssignMin(int* p, int v) {
    if (v < *p) return *p = v, true;
    return false;
}

struct Solution {
    int N;
    vector<int> A;
    vector<vector<int> > F;

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        F.resize(N);
        for (int i = N - 1; i >= 0; --i) {
            F[i].resize(N + 1 - i);
            for (int j = 0; j < F[i].size(); ++j) {
                if (j == 0 || j == 1) {
                    F[i][j] = 1;
                } else {
                    F[i][j] = INT_MAX;
                    if (A[i] == A[i + j - 1]) {
                        AssignMin(&F[i][j], F[i + 1][j - 2]);
                    }
                    for (int k = 1; k < j; ++k) {
                        AssignMin(&F[i][j], F[i][k] + F[i + k][j - k]);
                    }
                }
            }
        }
        printf("%d\n", F[0][N]);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
