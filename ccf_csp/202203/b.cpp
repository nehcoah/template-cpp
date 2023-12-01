#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int offset = 2.5e5;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(5e5);
    for (int i = 0; i < n; i++) {
        int t, c;
        cin >> t >> c;
        t += offset;
        d[t - c + 1]++;
        d[t + 1]--;
    }
    vector<int> cnt(5e5);
    for (int cur = 0, i = 0; i < cnt.size(); i++) {
        cur += d[i];
        cnt[i] = cur;
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        cout << cnt[q + k + offset] << "\n";
    }

    return 0;
}


