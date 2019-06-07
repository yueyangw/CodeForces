#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Segment {
    int Matched, Left, Right;

    void Combine(const Segment& left, const Segment& right) {
        int newMatched = min(left.Left, right.Right);
        Matched = left.Matched + right.Matched + newMatched;
        Left = left.Left - newMatched + right.Left;
        Right = right.Right - newMatched + left.Right;
    }
};

struct SegTree {
    int K, M;
    vector<Segment> Tree;

    SegTree(int n, const char* s):
        K(ilogb(n + 2) + 1),
        M(1 << K),
        Tree(M << 1)
    {
        for (int i = 0; i < n; ++i) {
            Tree[M + 1 + i].Matched = 0;
            Tree[M + 1 + i].Left = s[i] == '(';
            Tree[M + 1 + i].Right = s[i] == ')';
        }
        for (int i = M - 1; i >= 1; --i) {
            Tree[i].Combine(Tree[i + i], Tree[i + i + 1]);
        }
    }

    int Query(int left, int right) {
        left += M - 1;
        right += M + 1;
        Segment answerLeft = {0, 0, 0}, answerRight = {0, 0, 0};
        while ((left ^ right) != 1) {
            if ((left & 1) == 0) {
                Segment newAnswer;
                newAnswer.Combine(answerLeft, Tree[left ^ 1]);
                answerLeft = newAnswer;
            }
            if ((right & 1) != 0) {
                Segment newAnswer;
                newAnswer.Combine(Tree[right ^ 1], answerRight);
                answerRight = newAnswer;
            }
            left >>= 1;
            right >>= 1;
        }
        Segment answer;
        answer.Combine(answerLeft, answerRight);
        return answer.Matched;
    }
};

struct Solution {
    char S[1000001];
    int M, Left, Right;

    void Solve() {
        scanf("%s%d", S, &M);
        SegTree tree(strlen(S), S);
        for (int i = 0; i < M; ++i) {
            scanf("%d%d", &Left, &Right);
            printf("%d\n", tree.Query(Left, Right) << 1);
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}
