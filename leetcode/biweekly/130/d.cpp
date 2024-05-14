class Solution {
    int pow(long long x, long long n, long long mod) {
        long long res = 1 % mod;
        for (; n; n /= 2) {
            if (n % 2) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

    long long sum_e(long long k) {
        long long res = 0, n = 0, cnt1 = 0, sumI = 0;
        for (long long i = 63 - __builtin_clzll(k + 1); i; i--) {
            long long c = (cnt1 << i) + (i << (i - 1)); // 新增的幂次个数
            if (c <= k) {
                k -= c;
                res += (sumI << i) + ((i * (i - 1) / 2) << (i - 1));
                sumI += i; // 之前填的 1 的幂次之和
                cnt1++; // 之前填的 1 的个数
                n |= 1LL << i; // 填 1
            }
        }
        // 最低位单独计算
        if (cnt1 <= k) {
            k -= cnt1;
            res += sumI;
            n++; // 填 1
        }
        // 剩余的 k 个幂次，由 n 的低 k 个 1 补充
        while (k--) {
            res += __builtin_ctzll(n);
            n &= n - 1;
        }
        return res;
    }

public:
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> ans;
        for (auto& q : queries) {
            auto er = sum_e(q[1] + 1);
            auto el = sum_e(q[0]);
            ans.push_back(pow(2, er - el, q[2]));
        }
        return ans;
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-products-of-elements-of-big-array/solutions/2774549/olog-shi-tian-fa-pythonjavacgo-by-endles-w2l4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
