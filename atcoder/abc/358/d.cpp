#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < n && a[j] < b[i]) j += 1;
        if (j == n) {
            cout << -1 << endl;
            return 0;
        }
        ans += a[j++];
    }
    cout << ans << endl;

    return 0;
}

