#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), pre(n + 1), suf(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i], a[i] + n - i - 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], a[i] + i);
    }
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        ans = min(ans, max({pre[i], a[i], suf[i + 1]}));
    }
    cout << ans << endl;

    return 0;
}


