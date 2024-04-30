//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + max(0, b[idx[i]] - a[idx[i]]);
    }
    ll ans = 0, tot = 0;
    priority_queue<int> pq;
    for (int i = n; i >= 0; i--) {
        if (i < n) {
            pq.push(a[idx[i]]);
            tot += a[idx[i]];
        }
        while (pq.size() > k) {
            tot -= pq.top();
            pq.pop();
        }
        if (pq.size() == k) {
            ans = max(ans, sum[i] - tot);
        }
    }
    cout << ans << endl;
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
