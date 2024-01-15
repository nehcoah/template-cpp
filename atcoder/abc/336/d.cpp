#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        pre[i + 1] = min(pre[i] + 1, a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = min(suf[i + 1] + 1, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(pre[i + 1], suf[i]));
    }
    cout << ans << endl;


    return 0;
}
