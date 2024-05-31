#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m + 1), b(n + m + 1);
    for (int i = 0; i < n + m + 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n + m + 1; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    for (int i = 0; i < n + m + 1; i++) {
        cnt += a[i] > b[i];
    }
    if (cnt <= n) {
        swap(n, m);
        swap(a, b);
    }
    ll s1 = 0, s2 = 0;
    cnt = 0;
    for (int i = 0; i < n + m + 1; i++) {
        if (cnt > n || a[i] < b[i]) {
            s1 += b[i];
            s2 += b[i];
        } else {
            s1 += a[i];
            s2 += (cnt == n ? b[i] : a[i]);
            cnt += 1;
        }
    }
    cnt = 0;
    for (int i = 0; i < n + m + 1; i++) {
        if (a[i] > b[i] && cnt < n) {
            cout << s1 - a[i] << " \n"[i == n + m];
            cnt += 1;
        } else {
            cout << s2 - b[i] << " \n"[i == n + m];
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
