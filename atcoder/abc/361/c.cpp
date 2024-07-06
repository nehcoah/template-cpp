#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = a.back() - a[0];
    for (int i = n - k - 1; i < n; i++) {
        ans = min(ans, a[i] - a[i - (n - k) + 1]);
    }
    cout << ans << endl;

    return 0;
}
