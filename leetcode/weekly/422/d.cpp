using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;
template<typename T>
constexpr T power(T a, ull b) {
    T res {1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}

template<ull P>
constexpr ull mulMod(ull a, ull b) {
    ull res = a * b - ull(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template<typename U, U P>
requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x {0} {}

    template<typename T>
    requires std::integral<T>
    constexpr ModIntBase(T x_) : x {norm(x_ % T {P})} {}

    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }

    constexpr U val() const {
        return x;
    }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }

    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }

    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }

    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }

private:
    U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;

template<ull P>
using ModInt64 = ModIntBase<ull, P>;

constexpr u32 P = 1e9 + 7;
using mint = ModInt<P>;

struct Comb {
    int n;
    vector<mint> _fac;
    vector<mint> _invfac;
    vector<mint> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }

    void init(int m) {
        m = min<int>(m, P - 1);
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    mint fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    mint invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    mint inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    mint binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

class Solution {
public:
    int countBalancedPermutations(string s) {
        int n = s.size();
        int sum = 0;
        vector<int> cnt(10);
        for (char c : s) {
            sum += c - '0';
            cnt[c - '0'] += 1;
        }
        if (sum % 2 == 1) return 0;
        int tot = sum / 2;

        vector f(10, vector(n / 2 + 1, vector<unordered_map<int, mint>>(n - n / 2 + 1)));
        auto dfs = [&](auto self, int i, int d, int x, int y) -> mint {
            if (x < 0 || y < 0) return 0;
            if (i < 0) return int(d == 0 && x == 0 && y == 0);
            if (f[i][x][y].count(d)) return f[i][x][y][d];
            mint ans = 0;
            for (int j = 0; j <= cnt[i]; j++) {
                int k = cnt[i] - j;
                ans += comb.binom(x, j) * comb.binom(y, k) * self(self, i - 1, d + (j - k) * i, x - j, y - k);
            }
            return f[i][x][y][d] = ans;
        };
        auto ans = dfs(dfs, 9, 0, n / 2, n - n / 2);
        return ans.val();
    }
};
