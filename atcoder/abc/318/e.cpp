#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> lst(n + 1, -1), cnt(n + 1);
    vector<ll> sum(n);
    for (int i = n - 1; i >= 0; i--) {
        if (lst[a[i]] != -1) {
            sum[i] = sum[lst[a[i]]] + ll(lst[a[i]] - i - 1) * cnt[a[i]];
        }
        lst[a[i]] = i;
        cnt[a[i]]++;
    }
    ll ans = accumulate(sum.begin(), sum.end(), 0LL);
    cout << ans << endl;

    return 0;
}

