#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int p = 0;
    while (p < n && isdigit(s[p])) p += 1;
    int q = p;
    while (q < n && isalpha(s[q])) q += 1;
    if (q != n || !is_sorted(s.begin(), s.begin() + p) || !is_sorted(s.begin() + p, s.end())) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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
