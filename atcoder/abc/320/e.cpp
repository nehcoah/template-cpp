#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<array<ll, 3>> a(m);
    vector<ll> ans(n);
    for (int i = 0; i < m; i++) {
        ll t, w, s;
        cin >> t >> w >> s;
        a[i] = {t, w, s};
    }

    set<int> st;
    for (int i = 0; i < n; i++) st.insert(i);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (auto [t, w, s] : a) {
        while (!pq.empty() && pq.top().first <= t) {
            auto [ti, i] = pq.top(); pq.pop();
            st.insert(i);
        }
        if (st.empty()) continue;
        ans[*st.begin()] += w;
        pq.emplace(t + s, *st.begin());
        st.erase(st.begin());
    }

    for (int i = 0; i < n; i++) cout << ans[i] << endl;

    return 0;
}
