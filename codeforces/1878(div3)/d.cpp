#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> l(k), r(k);
    string s;
    cin>> s;
    for (int i = 0; i < k; i++) cin >> l[i], l[i]--;
    for (int i = 0; i < k; i++) cin >> r[i], r[i]--;
    int q; cin >> q;
    vector<int> m(n);
    for (int i = 0; i < q; i++) {
        int x; cin >> x; x--;
        m[x]++;
    }

    for (int i = 0; i < k; i++) {
        int a = l[i], b = r[i], sum = 0;
        for (int x = a; x <= (a + b) / 2; x++) {
            sum += m[x] + m[a + b - x];
            if (sum & 1) swap(s[x], s[a + b - x]);
        }
    }

    cout << s << endl;
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
