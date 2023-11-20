#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    map<ll, set<ll>> row, col, add, sub;
    map<pair<ll, ll>, ll> idx;
    ll ans = 0;
    for (int i = 0; i < p; i++) {
        ll x, y;
        cin >> x >> y;
        row[y].insert(x);
        col[x].insert(y);
        add[x + y].insert(x);
        sub[x - y].insert(x);
        ans ^= (i + 1) * x + y;
        idx[{x, y}] = i + 1;
    }

    for (int i = 0; i < q; i++) {
        ll u, v, t;
        cin >> u >> v >> t;
        vector<pair<ll, ll>> pos(8);
        vector<int> dx{0, -1, -1, -1, 0, 1, 1, 1};
        vector<int> dy{1, 1, 0, -1, -1, -1, 0, 1};

        auto it = row[v].lower_bound(u);
        if (it == row[v].begin()) pos[2] = {-1, u - 1};
        else pos[2] = {*prev(it), v};
        if (it == row[v].end()) pos[6] = {-1, n - u};
        else if (*it != u) pos[6] = {*it, v};
        else {
            it = next(it);
            if (it == row[v].end()) pos[6] = {-1, n - u};
            else pos[6] = {*it, v};
        }

        it = col[u].lower_bound(v);
        if (it == col[u].begin()) pos[4] = {-1, v - 1};
        else pos[4] = {u, *prev(it)};
        if (it == col[u].end()) pos[0] = {-1, m - v};
        else if (*it != v) pos[0] = {u, *it};
        else {
            it = next(it);
            if (it == col[u].end()) pos[0] = {-1, m - v};
            else pos[0] = {u, *it};
        }

        it = add[u + v].lower_bound(u);
        if (it == add[u + v].begin()) pos[1] = {-1, min(u - 1, m - v)};
        else pos[1] = {*prev(it), u + v - *prev(it)};
        if (it == add[u + v].end()) pos[5] = {-1, min(v - 1, n - u)};
        else if (*it != u) pos[5] = {*it, u + v - *it};
        else {
            it = next(it);
            if (it == add[u + v].end()) pos[5] = {-1, min(v - 1, n - u)};
            else pos[5] = {*it, u + v - *it};
        }

        it = sub[u - v].lower_bound(u);
        if (it == sub[u - v].begin()) pos[3] = {-1, min(u - 1, v - 1)};
        else pos[3] = {*prev(it), *prev(it) - u + v};
        if (it == sub[u - v].end()) pos[7] = {-1, min(n - u, m - v)};
        else if (*it != u) pos[7] = {*it, *it - u + v};
        else {
            it = next(it);
            if (it == sub[u - v].end()) pos[7] = {-1, min(n - u, m - v)};
            else pos[7] = {*it, *it - u + v};
        }

        ll k = 1e9;
        vector<ll> dis(8);
        for (int j = 0; j < 8; j++) {
            if (pos[j].first == -1) dis[j] = pos[j].second;
            else dis[j] = max(abs(pos[j].first - u), abs(pos[j].second - v));
            k = min(k, dis[j]);
        }
        bool border = true;
        for (int j = 0; j < 8; j++) {
            if (dis[j] == k && pos[j].first != -1) border = false;
        }
        if (border) continue;
        vector<array<ll, 3>> modify;
        for (int j = 0; j < 8; j++) {
            if (dis[j] > k || pos[j].first == -1) continue;
            ll x = pos[j].first, y = pos[j].second;
            ll id = idx[{x, y}];

            idx.erase({x, y});
            row[y].erase(x);
            col[x].erase(y);
            add[x + y].erase(x);
            sub[x - y].erase(x);
            ans ^= x * id + y;

            x = u + dx[(j + t) % 8] * dis[j];
            y = v + dy[(j + t) % 8] * dis[j];
            modify.push_back({x, y, id});
        }

        for (auto &mo: modify) {
            ll x = mo[0], y = mo[1], id = mo[2];
            idx[{x, y}] = id;
            row[y].insert(x);
            col[x].insert(y);
            add[x + y].insert(x);
            sub[x - y].insert(x);
            ans ^= x * id + y;
        }

    }

    cout << ans << endl;

    return 0;
}


