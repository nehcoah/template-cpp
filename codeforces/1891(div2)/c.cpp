#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, cnt = 0;
    ranges::sort(a);
    for (int i = 0, j = n - 1; i <= j; ) {
        if (i == j) {
            if (a[i] == 1) ans++;
            else ans += (a[j] - cnt + 1) / 2 + 1;
            break;
        } else {
            if (cnt + a[i] >= a[j]) {
                ans += a[j] - cnt + 1;
                a[i] -= a[j] - cnt;
                j--;
                if (i == j) {
                    ans += a[i] <= 1 ? a[i] : (a[i] + 1) / 2 + 1;
                    break;
                } else cnt = a[i], ans += a[i], i++;
            } else cnt += a[i], ans += a[i], i++;
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

