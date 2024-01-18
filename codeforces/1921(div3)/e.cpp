#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if (xa < xb) {
        if ((xb - xa) % 2 == 1) {
            if (abs(ya - yb) <= 1) {
                cout << "Alice\n";
            } else {
                if (ya > yb) {
                    if (yb - 1 + ya - yb - 1 > (xb - xa - 1) / 2) cout << "Draw\n";
                    else cout << "Alice\n";
                } else {
                    if (w - yb + yb - ya - 1 > (xb - xa - 1) / 2) cout << "Draw\n";
                    else cout << "Alice\n";
                }
            }
        } else {
            if (ya == yb) {
                cout << "Bob\n";
            } else {
                if (ya < yb) {
                    if (ya - 1 + yb - ya - 1 >= (xb - xa) / 2) cout << "Draw\n";
                    else cout << "Bob\n";
                } else {
                    if (w - ya + ya - yb - 1 >= (xb - xa) / 2) cout << "Draw\n";
                    else cout << "Bob\n";
                }
            }
        }
    } else {
        cout << "Draw\n";
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
