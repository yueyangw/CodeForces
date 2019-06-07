#include <cstdio>
#include <vector>
using namespace std;

char S[100001];

struct Node {
    vector<Node*> Child;

    Node(): Child(26) {}
};

struct Trie {
    Node *Root;

    Trie() { Root = new Node; }

    Node* Go(Node* current, char c) {
        Node*& next = current->Child[c - 'a'];
        if (!next) next = new Node;
        return next;
    }

    void Add(const char* s) {
        Node *current = Root;
        for (int i = 0; s[i]; ++i) current = Go(current, s[i]);
    }

    bool EnsureWin(Node* current) {
        for (int i = 0; i < current->Child.size(); ++i) {
            if (!current->Child[i]) continue;
            if (!EnsureWin(current->Child[i])) return true;
        }
        return false;
    }

    bool EnsureLose(Node* current) {
        bool isLeaf = true;
        for (int i = 0; i < current->Child.size(); ++i) {
            if (!current->Child[i]) continue;
            isLeaf = false;
            if (!EnsureLose(current->Child[i])) return true;
        }
        return isLeaf;
    }

    bool EnsureWin() { return EnsureWin(Root); }
    bool EnsureLose() { return EnsureLose(Root); }
};

struct Solution {
    int N, K;

    void Solve() {
        scanf("%d%d", &N, &K);
        Trie trie;
        for (int i = 0; i < N; ++i) {
            scanf("%s", S);
            trie.Add(S);
        }
        if (!trie.EnsureWin()) {
            printf("Second\n");
        } else if (trie.EnsureLose()) {
            printf("First\n");
        } else if (K % 2 == 0) {
            printf("Second\n");
        } else {
            printf("First\n");
        }
    }
};

int main() {
    Solution().Solve();
    return 0;
}
