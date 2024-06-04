#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) b[i - 1] = gcd(a[i], a[i - 1]);
    }

    int t = 0;
    for (int i = 0; i < n - 2; i++) {
        if (b[i] > b[i + 1]) t += 1;
    }
    if (t == 0 || (t == 1 && (b[0] > b[1] || b[n - 3] > b[n - 2]))) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n - 1; i++) {
        int x = t;
        x -= b[i] < b[i - 1];
        int g = gcd(a[i - 1], a[i + 1]);
        if (i - 1 > 0) {
            x -= b[i - 1] < b[i - 2];
            x += g < b[i - 2];
        }
        if (i + 1 < n - 1) {
            x -= b[i + 1] < b[i];
            x += b[i + 1] < g;
        }
        if (x == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

