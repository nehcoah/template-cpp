#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Node {
    // op:
    // 0 -> ~
    // 1 -> &
    // 2 -> |
    // 3 -> ^
    // 4 -> & ~
    // 5 -> | ~
    int op = 0;
    vector<int> in;
};

unordered_map<string, int> op_info{
        {"NOT", 0}, {"AND", 1}, {"OR", 2},
        {"XOR", 3}, {"NAND", 4}, {"NOR", 5}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q--) {
        int m, n;
        cin >> m >> n;
        vector<Node> info(n + m);
        vector<int> ind(n + m);
        vector<vector<int>> adj(m + n);
        for (int i = 0; i < m; i++) {
            Node c;
            c.op = -1;
            info[i] = c;
        }
        for (int i = 0; i < n; i++) {
            string op; cin >> op;
            int k; cin >> k;
            Node c;
            c.op = op_info[op];
            info[m + i] = c;
            ind[m + i] += k;
            for (int j = 0; j < k; j++) {
                string s; cin >> s;
                int pos = stoi(s.substr(1));
                if (s[0] == 'I') {
                    adj[pos - 1].push_back(m + i);
                } else {
                    adj[m + pos - 1].push_back(m + i);
                }
            }
        }

        int S; cin >> S;
        vector<vector<int>> mask(S);
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                mask[i].push_back(x);
            }
        }
        vector<vector<int>> order(S);
        for (int i = 0; i < S; i++) {
            int si; cin >> si;
            order[i].resize(si);
            for (int j = 0; j < si; j++) {
                cin >> order[i][j];
            }
        }

        queue<int> q;
        auto cur = ind;
        for (int i = 0; i < n + m; i++) {
            if (cur[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int y : adj[x]) {
                if (--cur[y] == 0) q.push(y);
            }
        }
        if (count(cur.begin(), cur.end(), 0) != m + n) {
            cout << "LOOP\n";
            continue;
        }

        auto calc = [&](int pos) -> int {
            auto cur = info[pos];
            int b = cur.in[0];
            if (cur.op == 0) b = !b;
            else if (cur.op == 1) {
                for (int i = 1; i < cur.in.size(); i++) b &= cur.in[i];
            } else if (cur.op == 2) {
                for (int i = 1; i < cur.in.size(); i++) b |= cur.in[i];
            } else if (cur.op == 3) {
                for (int i = 1; i < cur.in.size(); i++) b ^= cur.in[i];
            } else if (cur.op == 4) {
                for (int i = 1; i < cur.in.size(); i++) b &= cur.in[i];
                b = !b;
            } else {
                for (int i = 1; i < cur.in.size(); i++) b |= cur.in[i];
                b = !b;
            }
            return b;
        };

        for (int z = 0; z < S; z++) {
            for (int i = 0; i < m + n; i++) info[i].in.resize(0);
            vector<int> out(n);
            cur = ind;
            for (int i = 0; i < n + m; i++) {
                if (cur[i] == 0) q.push(i);
            }
            while (!q.empty()) {
                int x = q.front(); q.pop();
                if (x < m) {
                    for (int y : adj[x]) {
                        info[y].in.push_back(mask[z][x]);
                        if (--cur[y] == 0) q.push(y);
                    }
                } else {
                    out[x - m] = calc(x);
                    for (int y : adj[x]) {
                        info[y].in.push_back(out[x - m]);
                        if (--cur[y] == 0) q.push(y);
                    }
                }
            }
            for (int i = 0; i < order[z].size(); i++) {
                cout << out[order[z][i] - 1] << " \n"[i == order[z].size() - 1];
            }
        }
    }

    return 0;
}

