#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ans = 0;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) {
        bool ok = true;
        string m = to_string(i + 1);
        for (int j = 1; j < m.size(); j++) {
            if (m[j] != m[0]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        for (int x = 1; x <= d[i]; x++) {
            ok = true;
            for (char c : to_string(x)) {
                if (c != m[0]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

