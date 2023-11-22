// 65

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        p--;
        adj[p].push_back(i);
    }
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> res(n);
    function<multiset<ll>(int)> dfs = [&](int x) -> multiset<ll> {
        multiset<ll> st{a[x]};
        ll ans = 0;
        for (int y : adj[x]) {
            auto s = dfs(y);
            if (s.size() > st.size()) st.swap(s);
            for (ll z : s) st.insert(z);
        }
        if (st.size() > 1) {
            for (auto it = st.begin(); it != st.end(); it++) {
                if (it == st.begin()) ans += (*next(it) - *it) * (*next(it) - *it);
                else if (next(it) == st.end()) ans += (*it - *prev(it)) * (*it - *prev(it));
                else {
                    ll cur = min(*it - *prev(it), *next(it) - *it);
                    ans += cur * cur;
                }
            }
        }
        res[x] = ans;
        return st;
    };
    dfs(0);
    for (int i = 0; i < n; i++) cout << res[i] << "\n";

    return 0;
}


