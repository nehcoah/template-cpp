#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int N = 1e6 + 1;
vector<int> mnp, prime;
auto init = [](){
    mnp.assign(N, 0);
    for (int i = 2; i < N; i++) {
        if (mnp[i] == 0) {
            mnp[i] = i;
            prime.push_back(i);
        }
        for (int x : prime) {
            if (i * x >= N) break;
            mnp[i * x] = x;
            if (x == mnp[i]) break;
        }
    }
    return 0;
}();


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(N), s;

    int d = 1;
    auto get = [&](int x) {
        while (x > 1) {
            int y = mnp[x];
            x /= y;
            d /= a[y] + 1;
            a[y]++;
            d *= a[y] + 1;
        }
    };
    get(n);
    s.push_back(n);

    for (int i = 0; i < q; i++) {
        int k; cin >> k;
        if (k == 1) {
            int x; cin >> x;
            get(x); s.push_back(x);
            int mod = 1;
            for (int y : s) {
                mod = 1LL * mod * y % d;
            }
            if (mod == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            s.clear();
            s.push_back(n);
            a.assign(N, 0);
            d = 1;
            get(n);
        }
    }
    cout << endl;
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

