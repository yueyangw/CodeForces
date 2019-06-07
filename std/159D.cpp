#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct Solution {
    char S[2001];
    string SS;
    vector<int> Start, End;

    void Solve() {
        scanf("%s", S);
        bool head = true;
        for (int i = 0; S[i]; ++i) {
            if (!head) SS += '#';
            head = false;
            SS += S[i];
        }
        Start.resize(SS.size());
        End.resize(SS.size());
        for (int i = 0; i < SS.size(); ++i) {
            int p = i, q = i;
            for (; 0 <= p && q < SS.size(); --p, ++q) {
                if (SS[p] != SS[q]) break;
                ++Start[p];
                ++End[q];
            }
        }
        long long answer = 0;
        for (int i = 0; i < SS.size() - 2; i += 2) {
            End[i + 2] += End[i];
            answer += (long long)Start[i + 2] * End[i];
        }
        printf("%lld\n", answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
