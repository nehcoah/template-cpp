#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (k % 2 == 1) {
        cout << "No\n";
        return;
    }
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < n / 2; i++) {
        int t = n - i - 1 - i;
        if (t * 2 >= k) {
            swap(a[i], a[i + k / 2]);
            k = 0;
            break;
        } else {
            swap(a[i], a[n - i - 1]);
            k -= 2 * t;
        }
    }
    if (k) cout << "No\n";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] + 1 << " \n"[i == n - 1];
        }
    }
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

