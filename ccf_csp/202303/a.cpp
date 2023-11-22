#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = min(a, max(0, x1));
        y1 = min(b, max(0, y1));
        x2 = max(0, min(a, x2));
        y2 = max(0, min(b, y2));
        ans += (x2 - x1) * (y2 - y1);
    }
    cout << ans << endl;

    return 0;
}


