#include <cstdio>
#include <map>
#include <vector>
using namespace std;

const int M = 30000;

bool AssignMax(int* p, int v) {
    if (*p < v) return *p = v, true;
    return false;
}

struct Solution {
    int N, D;
    vector<int> A;
    vector<vector<int> > JumpFrom;

    int GetJumpFrom(int start, int d) {
        if (M < start) return 0;
        if (JumpFrom[d].size() == 0) {
            JumpFrom[d].resize(M + 1);
            for (int i = 0; i <= M; ++i) JumpFrom[d][i] = -1;
        }
        if (JumpFrom[d][start] != -1) return JumpFrom[d][start];
        int answer = 0;
        for (int i = d == 1 ? d : d - 1; i <= d + 1; ++i) {
            AssignMax(&answer, GetJumpFrom(start + d, i));
        }
        return JumpFrom[d][start] = answer + A[start];
    }

    void Solve() {
        scanf("%d%d", &N, &D);
        A.resize(M + 1);
        for (int i = 0; i < N; ++i) {
            int num;
            scanf("%d", &num);
            ++A[num];
        }
        JumpFrom.resize(M + 1);
        printf("%d\n", GetJumpFrom(0, D));
    }
};

int main() {
    Solution().Solve();
    return 0;
}
