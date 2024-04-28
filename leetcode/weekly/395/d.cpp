class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int x) {
            vector<int> cnt(1e5 + 1);
            int tot = 0;
            long long sum = 0;
            for (int i = 0, j = 0; i < n; i++) {
                if (cnt[nums[i]] == 0) tot += 1;
                cnt[nums[i]] += 1;
                while (j <= i && tot > x) {
                    if (cnt[nums[j]] == 1) tot -= 1;
                    cnt[nums[j]] -= 1;
                    j += 1;
                }
                sum += i - j + 1;
            }
            return sum < (1ll * n * (n + 1) / 2 + 1) / 2;
        };
        
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
