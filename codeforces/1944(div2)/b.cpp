#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> l_o, l_t, r_o, r_t;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (l_o.count(x)) l_o.erase(x), l_t.insert(x);
        else l_o.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (r_o.count(x)) r_o.erase(x), r_t.insert(x);
        else r_o.insert(x);
    }
    vector<int> l, r;
    while (l.size() < 2 * k) {
        if (!l_t.empty()) {
            l.push_back(*l_t.begin());
            l.push_back(*l_t.begin());
            l_t.erase(l_t.begin());
            r.push_back(*r_t.begin());
            r.push_back(*r_t.begin());
            r_t.erase(r_t.begin());
        } else {
            int x = *l_o.begin();
            l.push_back(x), r.push_back(x);
            l_o.erase(x), r_o.erase(x);
        }
    }
    for (int i = 0; i < l.size(); i++) {
        cout << l[i] << " \n"[i == l.size() - 1];
    }
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " \n"[i == r.size() - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
