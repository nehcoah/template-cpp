#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct Node {
    ll cost;
    int v;
    bool operator < (const Node &x) const {
        return cost == x.cost ? v < x.v : cost > x.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<set<Node>> info(n + 1);
    priority_queue<array<int, 4>> pq;
    map<pair<int, int>, ll> dis;
    int iso = n, cnt = 0;

    auto isolate = [&](int x) {
        return info[x].empty() || info[x].begin()->cost == 0;
    };

    auto check = [&](int x) {
        if (isolate(x)) return false;
        int y = info[x].begin()->v;
        return !isolate(y) && info[y].begin()->v == x;
    };

    auto update = [&](int u, int v, int x) {
        ll d = dis[{u, v}];
        dis[{u, v}] = d + x;

        iso -= isolate(u);
        cnt -= check(u);

        info[u].erase({d, v});
        info[u].insert({d + x, v});

        iso += isolate(u);
        cnt += check(u);
    };

    for (int i = 0; i < m; i++) {
        while (!pq.empty() && -pq.top()[0] <= i) {
            auto t = pq.top();
            pq.pop();
            update(t[1], t[2], -t[3]);
            update(t[2], t[1], -t[3]);
        }
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            pq.push({-i - y, u, v, x});
            update(u, v, x);
            update(v, u, x);
        }
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            if (isolate(x)) cout << 0 << "\n";
            else cout << info[x].begin()->v << "\n";
        }
        int p, q;
        cin >> p >> q;
        if (p) cout << iso << "\n";
        if (q) cout << cnt << "\n";
    }

    return 0;
}


