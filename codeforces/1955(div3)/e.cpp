// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int k = n; ; k -= 1) {
        vector<int> a(k);
        for (int i = 0; i < n; i++) {
            a[i % k] ^= '1' - s[i];
        }
        if (equal(a.begin() + 1, a.end(), a.begin())) {
            cout << k << endl;
            return;
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
