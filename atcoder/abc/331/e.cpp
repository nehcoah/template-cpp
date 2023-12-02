#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n), b(m), idx(n);
    vector<unordered_set<int>> cd(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < l; i++) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        cd[c].insert(d);
    }
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {
        return cd[x].size() < cd[y].size();
    });

    int ans = 0;
    set<pair<int, int>> st;
    unordered_set<int> pre;
    for (int i = 0; i < m; i++) st.insert({b[i], i});
    for (int i : idx) {
        for (int x : cd[i]) {
            if (pre.count(x) == 0) {
                st.erase(st.find({b[x], x}));
            } else {
                pre.erase(x);
            }
        }
        for (int x : pre) {
            st.insert({b[x], x});
        }
        if (!st.empty()) ans = max(ans, st.rbegin()->first + a[i]);
        pre = move(cd[i]);
    }
    cout << ans << endl;

    return 0;
}


