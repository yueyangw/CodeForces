#include <cstdio>
using namespace std;

struct Solution {
	char S[1000001];

	void Solve() {
		scanf("%s", S);
		int balance = 0, answer = 0;
		for (int i = 0; S[i]; ++i) {
			if (S[i] == '(') ++balance;
			if (S[i] == ')' && balance != 0) {
				--balance;
				++answer;
			}
		}
		printf("%d\n", answer << 1);
	}
};

int main() {
	Solution().Solve();
    return 0;
}
