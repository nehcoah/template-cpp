class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        
        auto check = [&](int x) {
            long long left = x + 1, mem = 0;
            vector<int> vis(n);
            for (int i = x; i >= 0; i--) {
                if (vis[changeIndices[i] - 1]) {
                    if (mem) left += 1, mem -= 1;
                    left = min(left, (long long) i + 1);
                    continue;
                }
                vis[changeIndices[i] - 1] = 1;
                left -= 1 + nums[changeIndices[i] - 1];
                mem += nums[changeIndices[i] - 1];
                if (left < 0) return false;
            }
            if (accumulate(vis.begin(), vis.end(), 0) != n) return false;
            return mem == 0;
        };
        
        int l = 0, r = m;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        return l == m ? -1 : l + 1;
    }
};
