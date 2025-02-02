class Solution {
public:
    string smallestNumber(string s, long long t) {
        long long tmp = t;
        for (int i = 9; i > 1; i--) {
            while (tmp % i == 0) {
                tmp /= i;
            }
        }
        if (tmp > 1) { // t 包含大于 7 的质因子
            return "-1";
        }

        int n = s.length();
        vector<long long> left_t(n + 1);
        left_t[0] = t;
        int i0 = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                i0 = i;
                break;
            }
            left_t[i + 1] = left_t[i] / gcd(left_t[i], s[i] - '0');
        }
        if (left_t[n] == 1) { // s 的数位之积是 t 的倍数
            return s;
        }

        // 假设答案和 s 一样长
        for (int i = i0; i >= 0; i--) {
            while (++s[i] <= '9') {
                long long tt = left_t[i] / gcd(left_t[i], s[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; j--) {
                    while (tt % k) {
                        k--;
                    }
                    tt /= k;
                    s[j] = '0' + k;
                }
                if (tt == 1) {
                    return s;
                }
            }
        }

        // 答案一定比 s 长
        string ans;
        for (int i = 9; i > 1; i--) {
            while (t % i == 0) {
                ans += '0' + i;
                t /= i;
            }
        }
        ans += string(max(n + 1 - (int) ans.length(), 0), '1');
        ranges::reverse(ans);
        return ans;
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/smallest-divisible-digit-product-ii/solutions/2984014/bao-sou-zuo-fa-lei-si-shu-wei-dp-by-endl-nkoo/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
