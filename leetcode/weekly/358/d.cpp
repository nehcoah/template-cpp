// 2818
// https://leetcode.cn/problems/apply-operations-to-maximize-score/description/
// fastpow, monotone stack

int s[100001];
auto init_ = [](){
    memset(s, 0, sizeof(s));
    for (int i = 2; i < 1e5 + 1; i++) {
        if (s[i] != 0) continue;
        for (int j = i; j < 1e5 + 1; j += i) {
            s[j] += 1;
        }
    }
    return 0;
}();


class Solution {
    const int mod = 1e9 + 7;
    long long pow(long long a, long long b){
        long long ans = 1LL;
        for (; b; b /= 2){
            if (b % 2) ans = ans * (a % mod) % mod;
            a = (a % mod) * (a % mod) % mod;
        }
        return ans;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), cnt1[n], cnt2[n];
        stack<int> stk;
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && s[nums[stk.top()]] < s[nums[i]]) stk.pop();
            if (!stk.empty()) cnt1[i] = i - stk.top();
            else cnt1[i] = i + 1;
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && s[nums[stk.top()]] <= s[nums[i]]) stk.pop();
            if (!stk.empty()) cnt2[i] = stk.top() - i;
            else cnt2[i] = n - i;
            stk.push(i);
        }

        int idx[n];
        iota(idx, idx + n, 0);
        sort(idx, idx + n, [&](int a, int b) {return nums[a] > nums[b];});
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int cur = idx[i];
            long long cnt = cnt1[cur] * cnt2[cur];
            if (cnt >= k) {
                ans = (ans * pow(nums[cur], k)) % mod;
                break;
            } else ans = (ans * pow(nums[cur], cnt)) % mod, k -= cnt;
        }
        return ans;
    }
};
