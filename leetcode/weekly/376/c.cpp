vector<long long> p;
auto init = [](){
    string s;
    auto dfs = [&](auto self, int i) {
        if (i == 5) {
            return;
        }
        for (char c = s.empty() ? '1' : '0'; c <= '9'; c++) {
            s.push_back(c);
            string cur = s.substr(0, s.size() - 1);
            reverse(cur.begin(), cur.end());
            cur = s + cur;
            p.push_back(stol(cur));
            cur = s;
            reverse(cur.begin(), cur.end());
            cur = s + cur;
            p.push_back(stol(cur));
            self(self, i + 1);
            s.pop_back();
        }
    };
    dfs(dfs, 0);
    ranges::sort(p);
    return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(n + 1);
        ranges::sort(nums);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        long long ans = numeric_limits<long long>::max();
        unordered_set<long long> st;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            auto it = lower_bound(p.begin(), p.end(), x);
            if (it != p.end()) st.insert(*it);
            if (it != p.begin()) st.insert(*prev(it));
        }
        for (long long x : st) {
            int y = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            ans = min(ans, x * y - sum[y] + sum[n] - sum[y] - x * (n - y));
        }
        return ans;
    }
};
