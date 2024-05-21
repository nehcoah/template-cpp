#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    map<pair<int, int>, int> cnt1;
    map<tuple<int, int, int>, int> cnt2;
    for (int i = 0; i < n - 2; i++) {
        auto b = make_pair(a[i + 1], a[i + 2]);
        auto c = make_tuple(a[i], a[i + 1], a[i + 2]);
        ans += cnt1[b] - cnt2[c];
        cnt1[b] += 1;
        cnt2[c] += 1;
    }
    cnt1.clear(), cnt2.clear();
    for (int i = 0; i < n - 2; i++) {
        auto b = make_pair(a[i], a[i + 2]);
        auto c = make_tuple(a[i], a[i + 1], a[i + 2]);
        ans += cnt1[b] - cnt2[c];
        cnt1[b] += 1;
        cnt2[c] += 1;
    }
    cnt1.clear(), cnt2.clear();
    for (int i = 0; i < n - 2; i++) {
        auto b = make_pair(a[i], a[i + 1]);
        auto c = make_tuple(a[i], a[i + 1], a[i + 2]);
        ans += cnt1[b] - cnt2[c];
        cnt1[b] += 1;
        cnt2[c] += 1;
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
