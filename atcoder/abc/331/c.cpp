#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {
        return a[x] > a[y];
    });
    ll sum = 0, pre = 0;
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ans[idx[i]] = pre;
        sum += a[idx[i]];
        if (i < n - 1 && a[idx[i + 1]] != a[idx[i]]) pre = sum;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}


