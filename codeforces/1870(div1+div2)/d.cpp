#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = n - 1; i > 0; i--) c[i - 1] = min(c[i - 1], c[i]);
    cin >> k;

    vector<int> ans(n);
    int t = k;
    for (int i = 0; i < n; i++) {
        int diff = c[i] - (i ? c[i - 1] : 0);
        if (diff > 0) t = min(t, k / diff);
        k -= diff * t;
        ans[i] = t;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// #include "bits/stdc++.h"

// using namespace std;
// using ll = long long;
// const int mod = 998244353;
// const int inf = 0x3f3f3f3f;

// void solve() {
//     ll n, k;
//     cin >> n;
//     vector<ll> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     cin >> k;

//     vector<ll> idx, diff(n);
//     for (int i = 0; i < n; i++) {
//         if (idx.empty()) {
//             if (a[i] <= k) {
//                 diff[i] = k / a[i];
//                 k %= a[i];
//                 idx.push_back(i);
//             }
//         } else {
//             while (!idx.empty() && a[i] <= a[idx.back()]) {
//                 k += diff[idx.back()] * a[idx.back()];
//                 diff[idx.back()] = 0;
//                 idx.pop_back();
//             }
//             diff[i] = k / a[i];
//             k %= a[i];
//             if (idx.empty()) {
//                 idx.push_back(i);
//                 continue;
//             }
//             while (!idx.empty()) {
//                 if (diff[idx.back()] == 0) {
//                     idx.pop_back();
//                     continue;
//                 }
//                 ll j = idx.back();
//                 ll cnt = min(diff[j], k / (a[i] - a[j]));
//                 if (cnt == 0) break;
//                 k -= cnt * (a[i] - a[j]);
//                 diff[j] -= cnt; diff[i] += cnt;
//                 if (diff[j] != 0) break;
//                 else idx.pop_back();
//             }
//             idx.push_back(i);
//         }
//     }

//     vector<ll> ans(n);
//     ll cur = 0;
//     for (int i = n - 1; i >= 0; i--) {
//         cur += diff[i];
//         ans[i] = cur;
//     }
//     for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;

//     while (t--) {
//         solve();
//     }

//     return 0;
// }
