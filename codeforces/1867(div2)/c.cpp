#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cur = 0;
    for (int x : a) {
        if (cur == x) cur++;
        else break;
    }
    if (cur == 0) {
        cout << 0 << endl;
        cout.flush();
        int x; cin >> x;
        return;
    }
    while (true) {
        cout << cur << endl;
        cout.flush();
        int x; cin >> x;
        if (x == 0) {
            cout << 0 << endl;
            cout.flush();
            int y; cin >> y;
            return;
        }
        cur = x;
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
