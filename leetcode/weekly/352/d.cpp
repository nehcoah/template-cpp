// https://leetcode.cn/problems/sum-of-imbalance-numbers-of-all-subarrays/

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool vis[n + 2];
        for (int i = 0; i < n; i++){
            memset(vis, 0, sizeof(vis));
            int cnt = 0;
            vis[nums[i]] = true;
            for (int j = i + 1; j < n; j++){
                int x = nums[j];
                if (!vis[x]){
                    if (!vis[x - 1]) cnt++;
                    if (vis[x + 1]) cnt--;
                    // cnt += 1 - vis[x - 1] - vis[x + 1];
                    vis[x] = true;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};
