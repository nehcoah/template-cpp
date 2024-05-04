// string hash, binary search, divide and conquer with a complexity of O(nlog(n)log(n)), n = 2e5. Time limit exceeded.
// maybe use z function.

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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    hash61 H(s);

    auto get = [&](int T) {
        auto check = [&](int x) {
            auto t = H.get_pre(x);
            int cnt = 1;
            for (int i = x; i + x <= n; i++) {
                if (H.get_hash(i, i + x - 1) == t) {
                    cnt += 1, i += x - 1;
                    if (cnt == T) return true;
                }
            }
            return cnt >= T;
        };
        int lo = 0, hi = min(n, n / T + 1);
        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (check(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    };

    vector<int> f(n + 1);
    auto dfs = [&](auto self, int l, int r) -> void {
        if (f[l] == f[r]) {
            for (int i = l; i <= r; i++) {
                f[i] = f[l];
            }
            return;
        }
        if (l + 1 == r) return;
        int mid = (l + r) >> 1;
        f[mid] = get(mid);
        self(self, l, mid);
        self(self, mid, r);
    };
    f[l] = get(l);
    f[r] = get(r);
    dfs(dfs, l, r);
    for (int i = r - 1; i >= l; i--) {
        f[i] = max(f[i], f[i + 1]);
    }
    for (int i = l; i <= r; i++) {
        cout << f[i] << " \n"[i == r];
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
