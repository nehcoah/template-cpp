// 2848
// https://leetcode.cn/problems/points-that-intersect-with-cars/description/

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        bool vis[101];
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < nums.size(); i++) {
            for (int s = nums[i][0]; s <= nums[i][1]; s++) vis[s] = 1;
        }
        return accumulate(vis, vis + 101, 0);
    }
};
