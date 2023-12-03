using ll = long long;

const int N = 1e5 + 1;
const int mod = 1e9 + 7;
vector<ll> fac, invfac;

ll power(ll x, ll y) {
    ll ans = 1;
    for (; y; y /= 2) {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
    }
    return ans;
}

int binom(int n, int m) {
    return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

auto init = []() {
    fac.resize(N);
    invfac.resize(N);
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    invfac.back() = power(fac.back(), mod - 2);
    for (int i = N - 1; i > 0; i--) {
        invfac[i - 1] = invfac[i] * i % mod;
    }
    return 0;
}();

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        vector<int> cnt, f;
        ll ans = 1, sum = 0;
        if (sick[0] > 0) {
            cnt.push_back(sick[0]);
            f.push_back(1);
            sum += sick[0];
        }
        for (int i = 1; i < sick.size(); i++) {
            if (sick[i - 1] + 1 == sick[i]) continue;
            int cur = sick[i] - sick[i - 1] - 1;
            cnt.push_back(cur);
            f.push_back(0);
            sum += cur;
        }
        if (sick.back() < n - 1) {
            cnt.push_back(n - 1 - sick.back());
            f.push_back(1);
            sum += cnt.back();
        }
        for (int i = 0; i < cnt.size(); i++) {
            ans = ans * binom(sum, cnt[i]) % mod;
            if (!f[i]) ans = ans * power(2, cnt[i] - 1) % mod;
            sum -= cnt[i];
        }
        return ans;
    }
};
