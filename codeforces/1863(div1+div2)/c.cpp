#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long b = (long long) n * (n + 1) / 2;
    for (int i = 0; i < n; i++) cin >> a[i], b -= a[i];
    a.push_back(b);
    k %= (n + 1);
    rotate(a.begin(), a.end() - k, a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
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
