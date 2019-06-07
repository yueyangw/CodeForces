#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<int> Discretize(vector<int>* a) {
    vector<int> b = *a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < a->size(); ++i) {
        (*a)[i] = lower_bound(b.begin(), b.end(), (*a)[i]) - b.begin();
    }
    return b;
}

struct SegTree {
    int K, M;
    vector<int> Tree;

    SegTree(int n):
        K(ilogb(n + 2) + 1),
        M(1 << K),
        Tree(M << 1) {}

    void Add(int x) {
        x += M + 1;
        while (x != 1) {
            ++Tree[x];
            x >>= 1;
        }
    }

    int GreaterThan(int x) {
        x += M + 1;
        int answer = 0;
        while (x != 1) {
            if ((x & 1) == 0) answer += Tree[x + 1];
            x >>= 1;
        }
        return answer;
    }
};

struct Solution {
    int N, M;
    vector<int> A;

    vector<int> InversePairL() {
        vector<int> answer(A.size());
        SegTree tree(M);
        for (int i = 0; i < A.size(); ++i) {
            answer[i] = tree.GreaterThan(A[i]);
            tree.Add(A[i]);
        }
        return answer;
    }

    vector<int> InversePairR() {
        vector<int> oldA = A;
        reverse(A.begin(), A.end());
        for (int i = 0; i < A.size(); ++i) A[i] = M - 1 - A[i];
        vector<int> answer = InversePairL();
        swap(A, oldA);
        reverse(answer.begin(), answer.end());
        return answer;
    }

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        M = Discretize(&A).size();
        vector<int> invL = InversePairL();
        vector<int> invR = InversePairR();
        long long answer = 0;
        for (int i = 0; i < N; ++i) answer += (long long)invL[i] * invR[i];
        printf("%lld\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
