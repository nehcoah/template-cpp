//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    pb -= 1, ps -= 1;
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] -= 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll b = 0, s = 0, sum = 0, cnt = 0;
    vector<int> vis(n);
    for (int x = pb; !vis[x] && cnt < k; x = p[x]) {
        b = max(b, sum + (k - cnt) * a[x]);
        sum += a[x], cnt += 1, vis[x] = 1;
    }
    sum = 0, cnt = 0;
    fill(vis.begin(), vis.end(), 0);
    for (int x = ps; !vis[x] && cnt < k; x = p[x]) {
        s = max(s, sum + (k - cnt) * a[x]);
        sum += a[x], cnt += 1, vis[x] = 1;
    }
    if (b > s) cout << "Bodya\n";
    else if (b == s) cout << "Draw\n";
    else cout << "Sasha\n";
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
