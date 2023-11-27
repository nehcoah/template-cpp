#include "bits/stdc++.h"

using namespace std;
using ll = long long;

vector<vector<int>> d;
void init(int n) {
    d.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            d[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ranges::sort(a);
    vector<ll> cnt(1e5 + 1), c(1e5 + 1);
    for (int i = 0; i < n; i++) {
        for (int p : d[a[i]]) {
            cnt[p] += c[p] * (n - i - 1);
            c[p]++;
        }
    }
    ll ans = 0;
    for (int i = 1e5; i >= 1; i--) {
        for (int j = 2 * i; j <= 1e5; j += i) {
            cnt[i] -= cnt[j];
        }
        ans += cnt[i] * i;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    init(1e5 + 1);
    while (t--) {
        solve();
    }

    return 0;
}


