// 20

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n), sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    auto check = [&](int l, int r) {
        int ans = numeric_limits<int>::max();
        for (int i = l; i < r / 2; i++) {
            ans = min(ans, sum[i + r / 2 + 1] - sum[i]);
        }
        return ans;
    };

    if (n % 2 == 0 && k) {
        cout << check(0, n) << endl;
    } else if (n % 2 == 1 && k == 0) {
        cout << min(check(0, n - 1), check(1, n)) << endl;
    } else {

    }

    return 0;
}


