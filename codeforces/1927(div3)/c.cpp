#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), ak(k + 1), bk(k + 1);;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= k) ak[a[i]] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] <= k) bk[b[i]] = 1;
    }
    vector<int> tot(k + 1);
    for (int i = 1; i <= k; i++) {
        tot[i] = ak[i] * 2 + bk[i];
        if (tot[i] == 0) {
            cout << "NO\n";
            return;
        }
    }
    int da = 0, db = 0;
    for (int i = 1; i <= k; i++) {
        if (tot[i] == 1) db++;
        else if (tot[i] == 2) da++;
        if (da > k / 2 || db > k / 2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
