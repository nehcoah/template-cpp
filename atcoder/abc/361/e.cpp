#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int, ll>>> adj(n);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a -= 1, b -= 1;
        ans += 2 * c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    auto check = [&](int x) -> pair<int, ll> {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        vector<ll> dis(n, -1);
        pq.emplace(0, x);
        while (!pq.empty()) {
            auto [d, y] = pq.top(); pq.pop();
            if (dis[y] != -1) continue;
            dis[y] = d;
            for (auto [z, w] : adj[y]) {
                pq.emplace(d + w, z);
            }
        }
        auto mx = max_element(dis.begin(), dis.end());
        return {mx - dis.begin(), *mx};
    };

    auto [s, _] = check(0);
    auto [t, d] = check(s);
    cout << ans - d << endl;

    return 0;
}
