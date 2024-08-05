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
    vector<int> cnt(30);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 29; j >= 0; j--) {
            if (a[i] >> j & 1) {
                cnt[j] = i - cnt[j] + 1;
            }
            ans += 1ll * cnt[j] * (1 << j);
        }
    }
    cout << ans - accumulate(a.begin(), a.end(), 0ll) << endl;

    return 0;
}
