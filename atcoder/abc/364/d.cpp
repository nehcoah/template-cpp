#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--) {
        int b, k;
        cin >> b >> k;
        int l = 0, r = 2e8;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = upper_bound(a.begin(), a.end(), b + mid) - lower_bound(a.begin(), a.end(), b - mid);
            if (cnt >= k) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }

    return 0;
}
