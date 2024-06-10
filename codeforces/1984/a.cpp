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
    int x = 0;
    for (; x < n - 1; x++) {
        if (a[x] - a[0] != a.back() - a[x + 1]) break;
    }
    if (x == n - 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (i <= x) cout << "R";
        else cout << "B";
    }
    cout << endl;
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

