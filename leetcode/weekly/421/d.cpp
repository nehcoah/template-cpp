const int mod = 1e9 + 7;

struct Matrix {
    int m, n;
    vector<vector<long long>> f;
    Matrix(int m, int n): m(m), n(n) {
        f.resize(m, vector<long long>(n));
    }
};

Matrix operator*(const Matrix &a, const Matrix &b) {
    int m = a.m, n = b.n;
    Matrix c(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < a.n; k++) {
                c.f[i][j] = (c.f[i][j] + a.f[i][k] * b.f[k][j]) % mod;
            }
        }
    }
    return c;
}

Matrix power(Matrix &a, long long b) {
    Matrix ans(a.m, a.m);
    for (int i = 0; i < a.m; i++) {
        ans.f[i][i] = 1;
    }
    for (; b; b /= 2) {
        if (b % 2) ans = ans * a;
        a = a * a;
    }
    return ans;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        Matrix cur(26, 26), base(1, 26);
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                cur.f[i][(i + j) % 26] = 1;
            }
        }
        for (char c : s) {
            base.f[0][c - 'a'] += 1;
        }
        auto x = base * power(cur, t);
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + x.f[0][i]) % mod;
        }
        return ans;
    }
};
