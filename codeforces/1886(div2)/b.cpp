#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;

    cout << fixed << setprecision(10);

    auto dis = [&](int x1, int y1, int x2 = 0, int y2 = 0) {
        return hypot(x2 - x1, y2 - y1);
    };

    auto ans = min({
        max(dis(ax, ay), dis(ax, ay, px, py)),
        max(dis(bx, by), dis(bx, by, px, py)),
        max({dis(ax, ay), dis(ax, ay, bx, by) / 2, dis(bx, by, px, py)}),
        max({dis(bx, by), dis(ax, ay, bx, by) / 2, dis(ax, ay, px, py)}),
    });

    cout << ans << endl;
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

