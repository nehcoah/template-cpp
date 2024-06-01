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
    map<int, int> mp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mp[a[i]] += 1;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (auto [k, v] : mp) {
        int s = lower_bound(a.begin(), a.end(), k) - a.begin();
        int i = 2;
        for (; k * i <= mx; i++) {
            int e = lower_bound(a.begin(), a.end(), k * i) - a.begin();
            ans += 1ll * v * (i - 1) * (e - s);
            s = e;
        }
        ans += 1ll * v * (i - 1) * (n - s);
    }
    for (auto [k, v] : mp) {
        ans = ans - 1ll * v * v + 1ll * (1 + v - 1) * (v - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}

