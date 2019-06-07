#include <cstdio>
#include <vector>
using namespace std;

bool AssignMax(int* p, int v) {
    if (*p < v) return *p = v, true;
    return false;
}

struct Solution {
    int N, K;
    vector<vector<int> > A;
    vector<int> LongPath;

    bool AllBefore(int x1, int x2) {
        for (int i = 0; i < K; ++i) {
            if (A[i][x2] <= A[i][x1]) return false;
        }
        return true;
    }

    int GetLongPath(int x) {
        if (LongPath[x] != -1) return LongPath[x];
        int answer = 0;
        for (int i = 0; i < N; ++i) {
            if (AllBefore(x, i)) AssignMax(&answer, GetLongPath(i) + 1);
        }
        return LongPath[x] = answer;
    }

    void Solve() {
        scanf("%d%d", &N, &K);
        A.resize(K);
        for (int i = 0; i < K; ++i) {
            A[i].resize(N);
            for (int j = 0; j < N; ++j) {
                int num = 0;
                scanf("%d", &num);
                A[i][num - 1] = j;
            }
        }
        LongPath.resize(N);
        for (int i = 0; i < N; ++i) LongPath[i] = -1;
        int answer = 0;
        for (int i = 0; i < N; ++i) AssignMax(&answer, GetLongPath(i));
        printf("%d\n", answer + 1);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
