#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int l = 0, r = 1, ans = 0;
    while (q--) {
        char h;
        int t;
        cin >> h >> t;
        t -= 1;
        if (h == 'L') {
            int cur = 0, ok = 1;
            for (int x = l; x != t; x = (x + 1) % n, cur++) {
                if (x == r) ok = false;
            }
            ans += ok ? cur : n - cur;
            l = t;
        } else {
            int cur = 0, ok = 1;
            for (int x = r; x != t; x = (x + 1) % n, cur++) {
                if (x == l) ok = false;
            }
            ans += ok ? cur : n - cur;
            r = t;
        }
    }
    cout << ans << endl;

    return 0;
}

