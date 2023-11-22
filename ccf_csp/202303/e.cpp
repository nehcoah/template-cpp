// 50
#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> interval(m);
    for (int i = 0; i < m; i++) {
        cin >> interval[i].first >> interval[i].second;
    }

    if (n <= 400) {
        int ans = 0;
        for (int l = 1; l <= n; l++) {
            for (int r = 1; r <= n; r++) {
                vector<int> d(n + 2);
                for (int k = 0; k < m; k++) {
                    if (interval[k].first >= l && interval[k].second <= r) {
                        d[interval[k].first] += 1, d[interval[k].second + 1] -= 1;
                    }
                }
                int cur = 0;
                for (int k = l; k <= r; k++) {
                    cur += d[k];
                    if (cur == 0) break;
                }
                if (cur) ans++;
            }
        }
        cout << ans << endl;
    } else {
        ll ans = 0;
        sort(interval.begin(), interval.end());
        for (int i = 0; i < m; ) {
            int j = i + 1;
            while (j < m && interval[j].first <= interval[j - 1].second + 1) j++;
            ans += 1LL * (j - i) * (j - i + 1) / 2;
            i = j;
        }
        cout << ans << endl;
    }

    return 0;
}


