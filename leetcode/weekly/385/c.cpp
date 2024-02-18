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

auto init = []() {
    sieve(1e6 + 1);
    return 0;
}();

class Solution {
    const int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        int m = mat.size(), n = mat[0].size();
        auto check = [&](int x, int y) {
            for (auto &d : dirs) {
                int x1 = x, y1 = y, cur = 0;
                cur = cur * 10 + mat[x1][y1];
                while (true) {
                    x1 += d[0], y1 += d[1];
                    if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n) break;
                    cur = cur * 10 + mat[x1][y1];
                    if (is_prime[cur] && cur > 10) mp[cur]++;
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                check(i, j);
            }
        }
        int ans = -1, mx = 0;
        for (auto [k, v] : mp) {
            if (v > mx) {
                mx = v, ans = k;
            } else if (v == mx) {
                ans = max(ans, k);
            }
        }
        return ans;
    }
};
