#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

bool AssignMax(int* p, int v) {
    if (*p < v) return *p = v, true;
    return false;
}

struct Solution {
    int N;
    vector<int> A, Max;

    vector<int> GetL() {
        vector<int> answer(N);
        stack<int> stack0;
        for (int i = 0; i < N; ++i) {
            while (!stack0.empty() && A[i] <= A[stack0.top()]) {
                stack0.pop();
            }
            answer[i] = stack0.empty() ? -1 : stack0.top();
            stack0.push(i);
        }
        return answer;
    }

    vector<int> GetR() {
        reverse(A.begin(), A.end());
        vector<int> answer = GetL();
        reverse(A.begin(), A.end());
        reverse(answer.begin(), answer.end());
        for (int i = 0; i < N; ++i) {
            answer[i] = N - 1 - answer[i];
        }
        return answer;
    }

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        Max.resize(N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        vector<int> largeL = GetL();
        vector<int> largeR = GetR();
        for (int i = 0; i < N; ++i) {
            int length = largeR[i] - largeL[i] - 1;
            AssignMax(&Max[length - 1], A[i]);
        }
        for (int i = N - 2; i >= 0; --i) {
            AssignMax(&Max[i], Max[i + 1]);
        }
        bool head = true;
        for (int i = 0; i < Max.size(); ++i) {
            if (!head) putchar(' ');
            head = false;
            printf("%d", Max[i]);
        }
        printf("\n");
    }
};


int main() {
    Solution().Solve();
    return 0;
}
