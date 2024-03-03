#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << "? 1 1" << endl;
    int dx, dy, dz; cin >> dx;
    int lx = 1 + dx > n ? n : 1 + dx, ly = 2 + dx - lx;
    int ry = 1 + dx > m ? m : 1 + dx, rx = 2 + dx - ry;
    cout << "? " << rx << " " << ry << endl;
    cin >> dy;
    cout << "? " << lx << " " << ly << endl;
    cin >> dz;
    if (dz & 1) {
        cout << "? " << rx + dy / 2 << " " << ry - dy / 2 << endl;
        int t; cin >> t;
        if (t == 0) cout << "! " << rx + dy / 2 << " " << ry - dy / 2 << endl;
        else cout << "! " << lx - dz / 2 << " " << ly + dz / 2 << endl;
    } else {
        cout << "? " << lx - dz / 2 << " " << ly + dz / 2 << endl;
        int t; cin >> t;
        if (t == 0) cout << "! " << lx - dz / 2 << " " << ly + dz / 2 << endl;
        else cout << "! " << rx + dy / 2 << " " << ry - dy / 2 << endl;
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
