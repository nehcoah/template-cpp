#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int p, t;
        cin >> p >> t;
        a[i] = {p, t};
    }
    int q;
    cin >> q;
    vector<int> query(q);
    for (int i = 0; i < q; i++) cin >> query[i];

    vector<ll> time(840);
    iota(time.begin(), time.end(), 0);
    for (ll &t : time) {
        for (int i = 0; i < n - 1; i++) {
            int mod = t % a[i].first;
            if (mod != 0) t += a[i].first - mod;
            t += a[i].second;
        }
    }

    for (int i = 0; i < q; i++) {
        ll cur = query[i] + x;
        int mod = cur % 840;
        cout << cur - mod + time[mod] + y << "\n";
    }

    return 0;
}

