#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), h(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
    for (int i = 0; i < n; i++) if (a[i] <= k) ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (h[i] % h[i + 1] == 0 && a[i] <= k) {
            int sum = 0, r = i;
            for (int l = i; r < n; r++) {
                if (r > i && h[r - 1] % h[r] != 0) break;
                sum += a[r];
                while (l < r && sum > k) sum -= a[l++];
                ans = max(ans, r - l + 1);
            }
            i = r - 1;
        }
    }
    cout << ans << endl;
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

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n), h(n), sum(n + 1);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < n; i++) cin >> h[i];

//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         sum[i + 1] = sum[i] + a[i];
//         if (a[i] <= k) ans = 1;
//     }
//     vector<int> idx;
//     for (int i = 0; i < n - 1; i++) if (h[i] % h[i + 1] != 0) idx.push_back(i);
//     for (int i = 0; i < n - 1; i++) {
//         if (h[i] % h[i + 1] == 0 && a[i] <= k) {
//             auto it = upper_bound(idx.begin(), idx.end(), i);
//             int l = 1, r = it == idx.end() ? n - i : *it - i + 1;
//             while (l < r) {
//                 int mid = l + r + 1 >> 1;
//                 if (sum[i + mid] - sum[i] <= k) l = mid;
//                 else r = mid - 1;
//             }
//             ans = max(ans, l);
//         }
//     }
//     cout << ans << endl;
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
