#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    int f = n == a, cur = a;
    for (int i = 0; i < q; i++) {
        a += s[i] == '+' ? 1 : -1;
        cur += s[i] == '+' ? 1 : 0;
        if (a == n) f = 1;
    }
    if (f) cout << "YES" << endl;
    else if (cur >= n) cout << "MAYBE" << endl;
    else cout << "NO" << endl;
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
