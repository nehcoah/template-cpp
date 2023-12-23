#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    if (k & 1) {
        int ans = 0;
        for (int i = 1; i < k; i += 2) {
            ans += a[i + 1] - a[i];
        }
        int cur = ans;
        for (int i = 2; i < k; i += 2) {
            cur -= a[i] - a[i - 1];
            cur += a[i - 1] - a[i - 2];
            ans = min(ans, cur);
        }
        cout << ans << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < k; i += 2) {
            ans += a[i + 1] - a[i];
        }
        cout << ans << endl;
    }

    return 0;
}

