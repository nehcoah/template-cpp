#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    sort(a.begin(), a.end());
    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int x = lower_bound(a.begin() + i + 1, a.end(), 1e8 - a[i]) - a.begin();
        ans += sum[x] - sum[i + 1] + 1ll * a[i] * (x - i - 1);
        ans += sum.back() - sum[x] + 1ll * a[i] * (n - x) - (ll) 1e8 * (n - x);
    }
    cout << ans << endl;

    return 0;
}
