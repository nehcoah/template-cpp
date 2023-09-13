//
// Created by Nehcoah on 2023/9/13.
//

#include <vector>

using namespace std;

template<typename T>
struct Matrix {
    int n, m;
    vector<vector<T>> A;

    Matrix(int n, int m) : n(n), m(m) {
        A.assign(n, vector<T>(m));
    }

    vector<T>& operator[](int i) {
        return A[i];
    }

    const vector<T>& operator[](int i) const {
        return A[i];
    }

    Matrix operator*(const Matrix& b) const {
        Matrix ans(n, b.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < m; k++)
                    ans[i][j] = ans[i][j] + A[i][k] * b[k][j];
        return ans;
    }

    Matrix pow(long long b) const {
        Matrix ans(n, n), a(n, n);
        for (int i = 0; i < n; i++) {
            ans[i][i] = 1;
            for (int j = 0; j < n; j++) a[i][j] = A[i][j];
        }
        for (; b; b /= 2) {
            if (b & 1) ans = ans * a;
            a = a * a;
        }
        return ans;
    }
};

struct Matrix_mod {
    int n, m, mod;
    vector<vector<int>> a;

    Matrix_mod(int n, int m, int mod) : n(n), m(m), mod(mod) {
        a.assign(n, vector<int>(m));
    }

    vector<int>& operator[](int i) {
        return a[i];
    }

    const vector<int>& operator[](int i) const {
        return a[i];
    }

    Matrix_mod operator*(const Matrix_mod& b) const {
        Matrix_mod ans(n, b.m, mod);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < m; k++)
                    ans[i][j] = (ans[i][j] + ((long long) a[i][k] * b[k][j]) % mod) % mod;
        return ans;
    }

    Matrix_mod pow(long long b) const {
        Matrix_mod ans(n, n, mod), A(n, n, mod);
        for (int i = 0; i < n; i++) {
            ans[i][i] = 1;
            for (int j = 0; j < n; j++) A[i][j] = (a[i][j] % mod + mod) % mod;
        }
        for (; b; b /= 2) {
            if (b & 1) ans = ans * A;
            A = A * A;
        }
        return ans;
    }
};

template<typename T>
T pow(T a, long long b) {
    T ans = T(1);
    for (; b; b /= 2) {
        if (b % 2) ans = ans * a;
        a = a * a;
    }
    return ans;
}

template<typename T>
T pow_mod(T a, long long b, T mod) {
    T ans = T(1);
    for (; b; b /= 2) {
        if (b % 2) ans = ans * (a % mod) % mod;
        a = (a % mod) * (a % mod) % mod;
    }
    return ans;
}

template<typename T>
vector<vector<T>> matrix_mul(vector<vector<T>> &a, vector<vector<T>> &b) {
    assert(a[0].size() == b.size());
    int m = a.size(), n = b[0].size(), t = a[0].size();
    vector ans(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < t; k++) {
                ans[i][j] += a[i][k] * a[k][j];
            }
        }
    }
    return ans;
}
