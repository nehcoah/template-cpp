class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<int> pos;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) pos.push_back(i);
            if (nums[i] == 1) {
                cur = max(cur, 1);
                if (i > 0 && nums[i - 1] == 1) {
                    cur = max(cur, 2);
                    if (i > 1 && nums[i - 2] == 1) {
                        cur = 3;
                    }
                }
            }
        }
        cout << cur << endl;
        if (cur >= k) return k - 1;
        if (cur + maxChanges >= k) return max(0, cur - 1) + (k - cur) * 2;
        
        int n = pos.size();
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + pos[i];
        }
        int s = k - maxChanges;
        long long ans = 1e18;
        for (int r = s; r <= n; r++) {
            int l = r - s;
            int mid = (l + r) >> 1;
            int id = pos[mid];
            long long left = 1ll * id * (mid - l) - (sum[mid] - sum[l]);
            long long right = sum[r] - sum[mid] - 1ll * id * (r - mid);
            ans = min(ans, left + right);
        }
        return ans + maxChanges * 2;
    }
};
