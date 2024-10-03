#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int l = 0; l < n; ) {
        if (l == n - 1) {
            ans += 1;
            break;
        }
        int r = l + 1;
        ll d = a[r] - a[l];
        while (r + 1 < n && a[r + 1] - a[r] == d) r += 1;
        ans += 1ll * (r - l + 1) * (r - l + 2) / 2 - 1;
        l = r;
    }
    cout << ans << endl;

    return 0;
}

