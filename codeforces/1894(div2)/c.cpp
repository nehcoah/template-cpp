#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int x = n, cur = n;
    vector<int> vis(n + 1);
    vis[n] = 1;
    while (true) {
        if (a[x - 1] > n) {
            cout << "No" << endl;
            return;
        }
        x = (x - a[x - 1] + n) % n;
        cur = n - x;
        if (vis[cur]) {
            cout << "Yes" << endl;
            return;
        }
        vis[cur] = 1;
        if (--k == 0) {
            cout << "Yes" << endl;
            return;
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

