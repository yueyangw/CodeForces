#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

bool AssignMax(int *p, int v) {
    if (*p < v) return *p = v, true;
    return false;
}

struct Solution {
    int N;
    vector<int> A;

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        sort(A.begin(), A.end());
        N = unique(A.begin(), A.end()) - A.begin();
        A.resize(N);
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = A[i] + A[i]; ; j += A[i]) {
                int index = lower_bound(A.begin(), A.end(), j) - A.begin() - 1;
                if (index == -1) continue;
                AssignMax(&answer, A[index] % A[i]);
                if (A.back() < j) break;
            }
        }
        printf("%d\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
