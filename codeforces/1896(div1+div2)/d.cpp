#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<int> pos;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] == 1) pos.insert(i);
    }
    for (int i = 0; i < q; i++) {
        int o; cin >> o;
        if (o == 1) {
            int s;
            cin >> s;
            int mn = pos.empty() ? n : min(*pos.begin(), n - *pos.rbegin() - 1);
            if (s > sum) cout << "NO" << endl;
            else if (s % 2 != sum % 2 && s > sum - mn * 2) cout << "NO" << endl;
            else cout << "YES" << endl;
        } else {
            int id, v;
            cin >> id >> v;
            id--;
            if (v == 2 && a[id] == 1) {
                pos.erase(id);
            }
            if (v == 1) pos.insert(id);
            sum += v - a[id];
            a[id] = v;
        }
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


