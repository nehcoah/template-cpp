#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    f -= 1, k -= 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = a[f];
    sort(a.begin(), a.end(), greater());
    if (a[k] == x && k != n - 1 && a[k + 1] == a[k]) cout << "MAYBE\n";
    else if (a[k] <= x) cout << "YES\n";
    else cout << "NO\n";
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

