#include <cstdio>
#include <vector>
using namespace std;

struct Solution {
    int N, Answer;
    vector<int> AllPrimes;
    vector<bool> Composite;

    void Generate() {
        Composite.resize(N);
        for (int i = 2; i < N; ++i) {
            if (!Composite[i]) {
                AllPrimes.push_back(i);
                for (long long j = (long long)i * i; j < N; j += i) {
                    Composite[j] = true;
                }
            }
        }
    }

    void Solve(long long current, int index, int num) {
        if (num == 0) {
            if (current <= N) ++Answer;
            return;
        }
        if (index == AllPrimes.size()) return;
        Solve(current, index + 1, num);
        while (current <= N) {
            current *= AllPrimes[index];
            Solve(current, index + 1, num - 1);
        }
    }
    
    void Solve() {
		scanf("%d", &N);
		Generate();
		Answer = 0;
		Solve(1, 0, 2);
		printf("%d\n", Answer);
	}
};

int main() {
	Solution().Solve();
    return 0;
}
