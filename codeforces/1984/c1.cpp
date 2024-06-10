#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

//void solve() {
//    int n;
//    cin >> n;
//    vector<ll> a(n);
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    vector<ll> sum(n + 1);
//    for (int i = 0; i < n; i++) {
//        sum[i + 1] = sum[i] + a[i];
//    }
//    ll ans = sum.back();
//    for (int i = 0; i < n; i++) {
//        if (sum[i + 1] < 0) ans = max(ans, abs(sum[i + 1]) + sum.back() - sum[i + 1]);
//    }
//    cout << ans << endl;
//}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> st{0};
    for (int i = 0; i < n; i++) {
        set<ll> nst;
        for (ll x : st) {
            nst.insert(x + a[i]);
            nst.insert(abs(x + a[i]));
        }
        st = set<ll>{*nst.begin(), *nst.rbegin()};
    }
    cout << *st.rbegin() << endl;
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

