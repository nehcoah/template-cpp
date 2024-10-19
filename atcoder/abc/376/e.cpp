#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

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
        return a[i] < a[j];
    });

    ll sum = 0, ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        pq.push(b[idx[i]]);
        sum += b[idx[i]];
    }
    ans = a[idx[k - 1]] * sum;
    for (int i = k; i < n; i++) {
        pq.push(b[idx[i]]);
        sum += b[idx[i]];
        int x = pq.top(); pq.pop();
        sum -= x;
        ans = min(ans, a[idx[i]] * sum);
    }
    cout << ans << "\n";
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

