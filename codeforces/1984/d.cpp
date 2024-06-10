#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

struct hash61 {
    static const uint64_t md = (1LL << 61) - 1;
    static uint64_t step;
    static vector<uint64_t> pw;

    uint64_t addmod(uint64_t a, uint64_t b) const {
        a += b;
        if (a >= md) a -= md;
        return a;
    }

    uint64_t submod(uint64_t a, uint64_t b) const {
        a += md - b;
        if (a >= md) a -= md;
        return a;
    }

    uint64_t mulmod(uint64_t a, uint64_t b) const {
        uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
        uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
        uint64_t ret = (l & md) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
        ret = (ret & md) + (ret >> 61);
        ret = (ret & md) + (ret >> 61);
        return ret - 1;
    }

    void ensure_pw(int sz) {
        int cur = (int) pw.size();
        if (cur < sz) {
            pw.resize(sz);
            for (int i = cur; i < sz; i++) {
                pw[i] = mulmod(pw[i - 1], step);
            }
        }
    }

    vector<uint64_t> pref;
    int n;

    template<typename T>
    hash61(const T& s) {
        n = (int) s.size();
        ensure_pw(n + 1);
        pref.resize(n + 1);
        pref[0] = 1;
        for (int i = 0; i < n; i++) {
            pref[i + 1] = addmod(mulmod(pref[i], step), s[i]);
        }
    }

    uint64_t get_hash(const int from, const int to) {
        assert(0 <= from && from <= to && to <= n - 1);
        return submod(pref[to + 1], mulmod(pref[from], pw[to - from + 1]));
    }

    uint64_t all() {
        return get_hash(0, n - 1);
    }

    uint64_t get_pre(int len) {
        assert(len <= n);
        return get_hash(0, len - 1);
    }

    uint64_t get_suf(int len) {
        assert(len <= n);
        return get_hash(n - len, n - 1);
    }
};

uint64_t hash61::step = (md >> 2) + rng() % (md >> 1);
vector<uint64_t> hash61::pw = vector<uint64_t>(1, 1);

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    if (count(s.begin(), s.end(), 'a') == n) {
        cout << n - 1 << endl;
        return;
    }

    vector<int> nxt(n + 1, n);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') nxt[i] = nxt[i + 1];
        else nxt[i] = i;
    }

    ll ans = 0;
    hash61 H(s);
    for (int i = nxt[0]; i < n; i++) {
        int mn = nxt[0], len = i - nxt[0] + 1, x = nxt[0];
        auto cur = H.get_hash(x, x + len - 1);
        bool ok = true;
        while (x < n) {
            if (x + len > n || H.get_hash(x, x + len - 1) != cur) {
                ok = false;
                break;
            }
            if (nxt[x + len] != n) mn = min(mn, nxt[x + len] - x - len);
            x = nxt[x + len];
        }
        if (ok) ans += mn + 1;
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

