// 数位dp

// Leetcode. 2376. https://leetcode.cn/problems/count-special-integers/description/
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int m = s.length(), dp[m][1 << 10];
        memset(dp, -1, sizeof(dp));
      
      	// i 表示当前统计到第i位
      	// mask 表示当前选择的数中的每位数字是否被选择
      	// isLimit 表示当前位的数字选择是否被限制（当 前i位每一位都和n的前i位相同时，被限制）为true被限制
      	// isNum 表示前i位是否选择数（即可以存在高位不选的情况）（或当前是不是数）为true表示高位填了数
      	// 记忆化的情况，只有当 !isLimit && isNum 时才需要记录
      	// 当被限制选择的数 和 跳过选择 的时候，不会存在再次递归到的情况
        function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool isLimit, bool isNum) -> int {
            if (i == m) return isNum;	// 递归到最后一位
            if (!isLimit && isNum && dp[i][mask] != -1) return dp[i][mask]; // 记忆化
            int ans = 0;
          	
          	// 跳过选择， 即当前位不填数字，此时前置的位数一定没有选择
          	// 前面未选择，当前位isLimit = false，不限制选择，而isNum = false，表示当前数位跳过
            if (!isNum) ans = dfs(i + 1, mask, false, false);
            
          	// 当前数位选择的上界
          	int up = isLimit ? s[i] - '0' : 9;
            for (int d = 1 - isNum; d <= up; d++){
                if ((mask >> d & 1) == 0) // 当前 前i位中没有d，进入递归（根据题目要求）
                  // 修改mask，当前isLimit == true且d为最高位时isLimit为true，填了数则isNum=true
                  ans += dfs(i + 1, mask | (1 << d), isLimit && d == up, true);
            }
            if (!isLimit && isNum) dp[i][mask] = ans; // 记忆化
            return ans;
        };
      	// 开始递归
      	// i = 0，没填数mask = 0，首位isLimit = true被限制，没填数isNum = false
        return dfs(0, 0, true, false);
    }
};

// Leetcode. 2999. https://leetcode.cn/problems/count-the-number-of-powerful-integers/description/
class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string low = to_string(start);
        string high = to_string(finish);
        int n = high.size();
        low = string(n - low.size(), '0') + low; // 补前导零，和 high 对齐
        int diff = n - s.size();

        vector<long long> memo(n, -1);
        function<long long(int, bool, bool)> dfs = [&](int i, bool limit_low, bool limit_high) -> long long {
            if (i == low.size()) {
                return 1;
            }

            if (!limit_low && !limit_high && memo[i] != -1) {
                return memo[i]; // 之前计算过
            }

            // 第 i 个数位可以从 lo 枚举到 hi
            // 如果对数位还有其它约束，应当只在下面的 for 循环做限制，不应修改 lo 或 hi
            int lo = limit_low ? low[i] - '0' : 0;
            int hi = limit_high ? high[i] - '0' : 9;

            long long res = 0;
            if (i < diff) { // 枚举这个数位填什么
                for (int d = lo; d <= min(hi, limit); d++) {
                    res += dfs(i + 1, limit_low && d == lo, limit_high && d == hi);
                }
            } else { // 这个数位只能填 s[i-diff]
                int x = s[i - diff] - '0';
                if (lo <= x && x <= min(hi, limit)) {
                    res = dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                }
            }

            if (!limit_low && !limit_high) {
                memo[i] = res; // 记忆化 (i,false,false)
            }
            return res;
        };
        return dfs(0, true, true);
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/count-the-number-of-powerful-integers/solutions/2595149/shu-wei-dp-shang-xia-jie-mo-ban-fu-ti-da-h6ci/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
