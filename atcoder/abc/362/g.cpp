#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct AhoCorasick {
    static constexpr int ALPHABET = 26;
    struct Node {
        int len;
        int link;
        array<int, ALPHABET> next;
        Node() : len{}, link{}, next{} {}
    };

    vector<Node> t;

    AhoCorasick() {
        init();
    }

    void init() {
        t.assign(2, Node());
        t[0].next.fill(1);
        t[0].len = -1;
    }

    int newNode() {
        t.emplace_back();
        return t.size() - 1;
    }

    int add(const vector<int> &a) {
        int p = 1;
        for (auto x : a) {
            if (t[p].next[x] == 0) {
                t[p].next[x] = newNode();
                t[t[p].next[x]].len = t[p].len + 1;
            }
            p = t[p].next[x];
        }
        return p;
    }

    int add(const string &a, char offset = 'a') {
        vector<int> b(a.size());
        for (int i = 0; i < a.size(); i++) {
            b[i] = a[i] - offset;
        }
        return add(b);
    }

    void work() {
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET; i++) {
                if (t[x].next[i] == 0) {
                    t[x].next[i] = t[t[x].link].next[i];
                } else {
                    t[t[x].next[i]].link = t[t[x].link].next[i];
                    q.push(t[x].next[i]);
                }
            }
        }
    }

    int next(int p, int x) {
        return t[p].next[x];
    }

    int next(int p, char c, char offset = 'a') {
        return next(p, c - 'a');
    }

    int link(int p) {
        return t[p].link;
    }

    int len(int p) {
        return t[p].len;
    }

    int size() {
        return t.size();
    }
};


int main() {
    string s;
    int q;
    cin >> s >> q;
    vector<string> t(q);
    for (int i = 0; i < q; i++) {
        cin >> t[i];
    }

    AhoCorasick ac;
    vector<int> end(q);
    for (int i = 0; i < q; i++) {
        end[i] = ac.add(t[i]);
    }
    ac.work();
    int m = ac.size();
    vector<vector<int>> g(m);
    vector<int> cnt(m);
    for (int i = 1; i < m; i++) {
        g[ac.link(i)].push_back(i);
    }
    int p = 1;
    for (char c : s) {
        p = ac.next(p, c);
        cnt[p] += 1;
    }
    auto dfs = [&](auto self, int x) -> void {
        for (int y : g[x]) {
            self(self, y);
            cnt[x] += cnt[y];
        }
    };
    dfs(dfs, 0);
    for (int i : end) {
        cout << cnt[i] << endl;
    }

    return 0;
}
