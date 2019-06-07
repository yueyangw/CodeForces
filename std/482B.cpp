#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

struct Segment {
    int V, M;
};

struct SegTree {
    int K, M;
    vector<Segment> Tree;

    SegTree(int n):
        K(ilogb(n + 2) + 1),
        M(1 << K),
        Tree(M << 1) {}

    int Push(int x) {
        if (x < M) {
            Tree[x + x].M |= Tree[x].M;
            Tree[x + x + 1].M |= Tree[x].M;
        }
        Tree[x].V |= Tree[x].M;
        Tree[x].M = 0;
        return x;
    }

    void BatchOr(int left, int right, int value) {
        left += M - 1;
        right += M + 1;
        for (int i = K - 1; i >= 0; --i) {
            int indexL = Push(left >> i);
            int indexR = Push(right >> i);
            if (1 < (indexL ^ indexR)) {
                if ((indexL & 1) == 0) Tree[indexL ^ 1].M |= value;
                if ((indexR & 1) != 0) Tree[indexR ^ 1].M |= value;
            }
        }
        for (int i = 1; i < K; ++i) {
            int indexL = Push(left >> i);
            int indexR = Push(right >> i);
            Tree[indexL].V =
                Tree[Push(indexL + indexL)].V &
                Tree[Push(indexL + indexL + 1)].V;
            Tree[indexR].V =
                Tree[Push(indexR + indexR)].V &
                Tree[Push(indexR + indexR + 1)].V;
        }
    }

    int Query(int left, int right) {
        left += M - 1;
        right += M + 1;
        int answer = -1;
        for (int i = K - 1; i >= 0; --i) {
            int indexL = Push(left >> i);
            int indexR = Push(right >> i);
            if (1 < (indexL ^ indexR)) {
                if ((indexL & 1) == 0) answer &= Tree[Push(indexL ^ 1)].V;
                if ((indexR & 1) != 0) answer &= Tree[Push(indexR ^ 1)].V;
            }
        }
        return answer;
    }

    void PrintAll(int n) {
        for (int i = 1; i < Tree.size(); ++i) Push(i);
        bool head = true;
        for (int i = 0; i < n; ++i) {
            if (!head) putchar(' ');
            head = false;
            printf("%d", Tree[i + M + 1].V);
        }
        printf("\n");
    }
};

struct Requirement {
    int L, R, Q;
};

struct Solution {
    int N, M;
    vector<Requirement> Req;

    void Solve() {
        scanf("%d%d", &N, &M);
        SegTree tree(N);
        Req.resize(M);
        for (int i = 0; i < M; ++i) {
            scanf("%d%d%d", &Req[i].L, &Req[i].R, &Req[i].Q);
            tree.BatchOr(Req[i].L, Req[i].R, Req[i].Q);
        }
        bool interesting = true;
        for (int i = 0; i < M; ++i) {
            if (tree.Query(Req[i].L, Req[i].R) != Req[i].Q) {
                interesting = false;
                break;
            }
        }
        if (interesting) {
            printf("YES\n");
            tree.PrintAll(N);
        } else {
            printf("NO\n");
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}
