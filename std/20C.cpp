#include <cstdio>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

bool AssignMin(long long* p, long long v) {
    if (v < *p) return *p = v, true;
    return false;
}

struct Edge {
    int Target, Cost;
};

struct TempLabel {
    int No;
    long long Distance;

    bool operator<(const TempLabel& that) const {
        return Distance > that.Distance;
    }
};

struct Solution {
    int N, M;
    vector<vector<Edge> > E;
    vector<int> From;
    vector<long long> Distance;
    vector<bool> Permanent;
    priority_queue<TempLabel> Queue;

    bool Dijkstra() {
        Distance.resize(N);
        for (int i = 0; i < N; ++i) Distance[i] = INT_MAX;
        Distance[0] = 0;
        From.resize(N);
        Permanent.resize(N);
        TempLabel tempLabel = {0, 0};
        Queue.push(tempLabel);
        while (!Permanent[N - 1]) {
            if (Queue.empty()) return false;
            int topNo = Queue.top().No;
            long long topDistance = Queue.top().Distance;
            Queue.pop();
            if (Permanent[topNo]) continue;
            Permanent[topNo] = true;
            for (int j = 0; j < E[topNo].size(); ++j) {
                if (Permanent[E[topNo][j].Target]) continue;
                long long newDistance = topDistance + E[topNo][j].Cost;
                if (AssignMin(&Distance[E[topNo][j].Target], newDistance)) {
                    From[E[topNo][j].Target] = topNo;
                    TempLabel tempLabel = {E[topNo][j].Target, newDistance};
                    Queue.push(tempLabel);
                }
            }
        }
        return true;
    }

    void Solve() {
        scanf("%d%d", &N, &M);
        E.resize(N);
        for (int i = 0; i < M; ++i) {
            int v1, v2, w;
            scanf("%d%d%d", &v1, &v2, &w);
            Edge e1 = {v2 - 1, w}, e2 = {v1 - 1, w};
            E[v1 - 1].push_back(e1);
            E[v2 - 1].push_back(e2);
        }
        if (Dijkstra()) {
            vector<int> route;
            route.push_back(N - 1);
            while (route.back() != 0) route.push_back(From[route.back()]);
            bool head = true;
            for (int i = route.size() - 1; i >= 0; --i) {
                if (!head) putchar(' ');
                head = false;
                printf("%d", route[i] + 1);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}
