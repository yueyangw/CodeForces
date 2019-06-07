#include <algorithm>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, M;
    vector<int> A, B;

    void Solve() {
        scanf("%d%d", &N, &M);
        A.resize(N);
        for (int i = 0; i < N; ++i) scanf("%d%*s", &A[i]);
        B.resize(N - 1);
        for (int i = 0; i < N - 1; ++i) B[i] = INT_MAX;
        B[0] = INT_MIN;
        for (int i = 0; i < N; ++i) {
            int index = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
            B[index] = A[i];
        }
        int index = lower_bound(B.begin(), B.end(), INT_MAX) - B.begin() - 1;
        printf("%d\n", N - index);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
