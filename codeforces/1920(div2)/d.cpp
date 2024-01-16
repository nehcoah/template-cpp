#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    const ll inf = 1e18;
    int n, q;
    cin >> n >> q;
    vector<vector<int>> nums(1);
    vector<int> cp{1};
    vector<ll> sz{0};
    for (int i = 0; i < n; i++) {
        int b, x;
        cin >> b >> x;
        if (b == 1) {
            nums.back().push_back(x);
        } else {
            if (sz.back() < inf) {
                sz.push_back(sz.back() <= inf / cp.back() ? sz.back() * cp.back() + nums.back().size() : inf);
                cp.push_back(x + 1);
                nums.emplace_back();
            }
        }
    }
    for (int i = 0; i < q; i++) {
        ll k; cin >> k; k--;
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (k / cp[j] >= sz[j]) {
                cout << nums[j][k - cp[j] * sz[j]] << " \n"[i == q - 1];
                break;
            } else {
                k %= sz[j];
            }
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
