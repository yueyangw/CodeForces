#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

struct Query {
    int Id, Left, Right, W1, W2;

    bool operator<(const Query& that) {
        return W1 < that.W1 || W1 == that.W1 && W2 < that.W2;
    }
};

struct Solution {
    vector<Query> Q;
    int BlockSize;
    long long Answer;
    int Left, Right;
    vector<int> Size;

    void Set(int id, int left, int right) {
        Q[id].Id = id;
        Q[id].Left = left;
        Q[id].Right = right;
        Q[id].W1 = Q[id].Left / BlockSize;
        Q[id].W2 = Q[id].Right / BlockSize;
        if (Q[id].W1 % 2 == 0) Q[id].W2 = -Q[id].W2;
    }

    void Adjust(int a, int change) {
        Answer -= (long long)a * Size[a] * Size[a];
        Size[a] += change;
        Answer += (long long)a * Size[a] * Size[a];
    }

	void Solve() {
		int n, t;
		scanf("%d%d", &n, &t);
		vector<int> a(n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		Q.resize(t);
		BlockSize = (int)sqrt(1.5 * n * n / t) + 1;
		for (int i = 0; i < t; ++i) {
			int left, right;
			scanf("%d%d", &left, &right);
			Set(i, left, right);
		}
		sort(Q.begin(), Q.end());
		Answer = 0;
		Left = 1;
		Right = 0;
		Size.resize(*max_element(a.begin(), a.end()) + 1);
		vector<long long> answer(t);
		for (int i = 0; i < t; ++i) {
			while (Left > Q[i].Left) {
				Adjust(a[(--Left) - 1], 1);
			}
			while (Right < Q[i].Right) {
				Adjust(a[(++Right) - 1], 1);
			}
			while (Left < Q[i].Left) {
				Adjust(a[(Left++) - 1], -1);
			}
			while (Right > Q[i].Right) {
				Adjust(a[(Right--) - 1], -1);
			}
			answer[Q[i].Id] = Answer;
		}
		for (int i = 0; i < t; ++i) printf("%lld\n", answer[i]);
	}
};

int main() {
	Solution().Solve();
	return 0;
}
