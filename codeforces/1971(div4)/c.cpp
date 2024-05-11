#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if (a == min({a, b, c, d}) && b == max({a, b, c, d})) cout << "NO\n";
    else if (c == min({a, b, c, d}) && d == max({a, b, c, d})) cout << "NO\n";
    else if (c > b || d < a) cout << "NO\n";
    else cout << "YES\n";
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
