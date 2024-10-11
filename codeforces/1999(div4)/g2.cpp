#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int l = 2, r = 999;
    while (true) {
        int t = (r - l) / 3;
        int ml = l + t, mr = r - t;
        cout << "? " << ml << " " << mr << endl;
        int x; cin >> x;
        if (x == (ml + 1) * (mr + 1)) r = ml;
        else if (x == ml * (mr + 1)) l = ml + 1, r = mr;
        else l = mr + 1;
        if (l == r) {
            cout << "! " << l << endl;
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

