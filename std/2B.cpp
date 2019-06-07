#include <algorithm>
#include <climits>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int HowMany(int n, int factor) {
    if (n == 0) return INT_MAX >> 1;
    int answer = 0;
    while (n % factor == 0) {
        n /= factor;
        ++answer;
    }
    return answer;
}

bool AssignMin(int* p, int v) {
    if (v < *p) return *p = v, true;
    return false;
}

struct Solution {
    int N, Length;
    vector<vector<int> > A, F;
    string Path;

    void FindAnswer(int factor) {
        F = A;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                F[i][j] = INT_MAX >> 1;
                int howMany = HowMany(A[i][j], factor);
                if (i == 0 && j == 0) F[i][j] = howMany;
                if (i != 0) AssignMin(&F[i][j], howMany + F[i - 1][j]);
                if (j != 0) AssignMin(&F[i][j], howMany + F[i][j - 1]);
            }
        }
        if (AssignMin(&Length, F[N - 1][N - 1])) {
            Path = GetPath();
        }
    }

    bool GoX(int x, int y) {
        if (x == 0) return false;
        if (y == 0) return true;
        return F[x - 1][y] < F[x][y - 1];
    }

    string GetPath() {
        string answer;
        int x = N - 1, y = N - 1;
        while (x != 0 || y != 0) {
            if (GoX(x, y)) {
                --x;
                answer += 'D';
            } else {
                --y;
                answer += 'R';
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }

    void FindAnswer0() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 0 && AssignMin(&Length, 1)) {
                    Path = GetPath0(i);
                }
            }
        }
    }

    string GetPath0(int x) {
        string answer;
        for (int i = 0; i < x; ++i) answer += 'D';
        for (int i = 0; i < N - 1; ++i) answer += 'R';
        for (int i = x; i < N - 1; ++i) answer += 'D';
        return answer;
    }

    void Solve() {
        scanf("%d", &N);
        A.resize(N);
        for (int i = 0; i < N; ++i) {
            A[i].resize(N);
            for (int j = 0; j < N; ++j) scanf("%d", &A[i][j]);
        }
        Length = INT_MAX;
        FindAnswer(2);
        FindAnswer(5);
        FindAnswer0();
        printf("%d\n%s\n", Length, Path.c_str());
    }
};

int main() {
    Solution().Solve();
    return 0;
}
