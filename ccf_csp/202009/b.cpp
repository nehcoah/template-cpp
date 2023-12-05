#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, t, x1, y1, x2, y2;
    cin >> n >> k >> t >> x1 >> y1 >> x2 >> y2;

    int ans = 0, res = 0;
    for (int i = 0; i < n; i++) {
        bool in = false, stay = false;
        int cnt = 0;
        for (int j = 0; j < t; j++) {
            int x, y;
            cin >> x >> y;
            if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                cnt++;
                in = true;
                if (cnt == k) stay = true;
            } else {
                cnt = 0;
            }
        }
        ans += in;
        res += stay;
    }
    cout << ans << endl;
    cout << res << endl;

    return 0;
}

