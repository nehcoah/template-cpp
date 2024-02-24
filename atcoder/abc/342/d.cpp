#include "bits/stdc++.h"

using namespace std;
using ll = long long;

vector<int> is_prime, minp, prime;
void sieve(int n) {
    is_prime.assign(n + 1, true);
    minp.assign(n + 1, 0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            minp[i] = i;
        }
        for (auto x : prime) {
            if (i * x > n) break;
            is_prime[i * x] = false;
            minp[i * x] = x;
            if (x == minp[i]) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(2e5 + 1);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0, cnt = 0;
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (x == 0) {
            cnt += 1;
            continue;
        }
        int cur = 1;
        while (x > 1) {
            int p = minp[x], c = 0;
            while (x % p == 0) {
                x /= p;
                c += 1;
            }
            if (c % 2) cur *= p;
        }
        ans += mp[cur];
        mp[cur] += 1;
    }
    ans += 1ll * cnt * (n - cnt) + (cnt - 1) * cnt / 2;
    cout << ans << endl;

    return 0;
}
