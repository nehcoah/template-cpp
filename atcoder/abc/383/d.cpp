#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

//template <typename K, typename V, typename Comp = std::less<K>>
//using ordered_map = __gnu_pbds::tree<
//        K, V, Comp,
//        __gnu_pbds::rb_tree_tag,
//        __gnu_pbds::tree_order_statistics_node_update
//>;
//
//template <typename K, typename Comp = std::less<K>>
//using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;
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

    sieve(2e6 + 1);

    ll n; cin >> n;

    int ans = 0;
    for (ll i = 2; i * i <= n; i++) {
        int p1 = minp[i], p2 = i / minp[i];
        if (p1 != p2 && is_prime[p2]) ans += 1;
    }

    for (ll i : prime) {
        ll x = i * i * i * i;
        if (x * x > n) break;
        ans += 1;
    }
    cout << ans << endl;

    return 0;
}

