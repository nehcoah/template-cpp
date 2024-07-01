#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] - 1] += 1;
    }
    vector<int> f(n + 1, 1e9);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) continue;
        vector<int> g(n + 1, 1e9);
        for (int j = 0; j < n; j++) {
            g[j + 1] = f[j] + 1;
        }
        for (int j = cnt[i]; j <= n; j++) {
            g[j - cnt[i]] = min(g[j - cnt[i]], f[j]);
        }
        f.swap(g);
    }
    cout << *min_element(f.begin(), f.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
