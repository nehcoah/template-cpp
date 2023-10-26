using ll = long long;
const int N = 2e5 + 1;
const int mod = 998244353;

ll power(ll a, ll b) {
    ll ans = 1;
    for (; b; b /= 2) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

vector<ll> fac, invfac, inv;
auto init = []() {
    fac.resize(N);
    invfac.resize(N);
    inv.resize(N);
    fac[0] = 1; invfac[0] = 1; inv[0] = 0;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    invfac[N - 1] = power(fac[N - 1], mod - 2);
    for (int i = N - 1; i; i--) {
        invfac[i - 1] = invfac[i] * i % mod;
        inv[i] = invfac[i] * fac[i - 1] % mod;
    }
    return 0;
}();

int binom(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}

class Solution {
public:
    int beautifulString(string s) {
        int n = s.size();
        if (n == 1) return 1;
        ll ans = 1, cur = 1;
        vector<int> cnt(2);
        cnt[s[0] - '0']++;
        for (int i = 1; i < n; i++) {
            cnt[s[i] - '0']++;
            int x = i - cnt[(s[i] - '0') ^ 1];
            if (s[i] != s[i - 1]) cur = (power(2, i - 1) - cur + mod) % mod;
            cur = (cur * 2 % mod + binom(i - 1, x)) % mod;
            ans = (ans + cur) % mod;
        }
        return ans;
    }
};
