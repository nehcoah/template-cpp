#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto t = s;
    int ans = 0;
    do {
        bool good = true;
        for (int i = 0; i <= n - k; i++) {
            bool ok = false;
            for (int x = i, y = i + k - 1; x < y; x++, y--) {
                if (s[x] != s[y]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                good = false;
                break;
            }
        }
        ans += good;
        next_permutation(s.begin(), s.end());
    } while (s != t);
    cout << ans << endl;

    return 0;
}
