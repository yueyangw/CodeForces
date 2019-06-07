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
    int Target;
    long long Cost;
};

struct TempLabel {
    int No;
    long long Distance;

    bool operator<(const TempLabel& that) const {
        return Distance > that.Distance;
    }
};

struct Solution {
    int N, M, K;
    vector<vector<Edge> > E;
    vector<long long> Route, Distance;
    vector<bool> Permanent, Unique;
    priority_queue<TempLabel> Queue;

    void Dijkstra() {
        Distance.resize(N);
        for (int i = 0; i < N; ++i) Distance[i] = LONG_LONG_MAX;
        Distance[0] = 0;
        Unique.resize(N);
        Permanent.resize(N);
        TempLabel tempLabel = {0, 0};
        Queue.push(tempLabel);
        while (true) {
            if (Queue.empty()) return;
            int topNo = Queue.top().No;
            long long topDistance = Queue.top().Distance;
            Queue.pop();
            if (Permanent[topNo]) continue;
            Permanent[topNo] = true;
            for (int j = 0; j < E[topNo].size(); ++j) {
                int target = E[topNo][j].Target;
                if (Permanent[target]) continue;
                long long newDistance = topDistance + E[topNo][j].Cost;
                if (AssignMin(&Distance[target], newDistance)) {
                    Unique[target] = true;
                    TempLabel tempLabel = {target, newDistance};
                    Queue.push(tempLabel);
                } else if (Distance[target] == newDistance) {
                    Unique[target] = false;
                }
            }
        }
    }

    void Solve() {
        scanf("%d%d%d", &N, &M, &K);
        E.resize(N);
        for (int i = 0; i < M; ++i) {
            int v1, v2, w;
            scanf("%d%d%d", &v1, &v2, &w);
            Edge e1 = {v2 - 1, w}, e2 = {v1 - 1, w};
            E[v1 - 1].push_back(e1);
            E[v2 - 1].push_back(e2);
        }
        Route.resize(N);
        for (int i = 0; i < N; ++i) Route[i] = LONG_LONG_MAX;
        Route[0] = 0;
        for (int i = 0; i < K; ++i) {
            int s, y;
            scanf("%d%d", &s, &y);
            AssignMin(&Route[s - 1], y);
        }
        for (int i = 1; i < N; ++i) {
            if (Route[i] == LONG_LONG_MAX) continue;
            Edge e = {i, Route[i]};
            E[0].push_back(e);
        }
        Dijkstra();
        int answer = 0;
        for (int i = 1; i < N; ++i) {
            if (Distance[i] == Route[i] && Unique[i]) ++answer;
        }
        printf("%d\n", K - answer);
    }
};

int main() {
    Solution().Solve();
    return 0;
}
