// https://leetcode.cn/problems/find-a-good-subset-of-the-matrix/

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), cnt = 0;
        vector<pair<int, int>> nums;
        for (auto& g : grid){
            int mask = 0;
            for (int i = 0; i < g.size(); i++) mask <<= 1, mask |= g[i];
            nums.emplace_back(mask, cnt++);
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end(), [](auto& a, auto& b){
            return a.first == b.first;
        }), nums.end());
        if (nums.size() == 1){
            if (nums[0].first == 0) return {nums[0].second};
            else return {};
        }
        for (int i = 0; i < nums.size(); i++){
            for (int j = 1; j < nums.size(); j++){
                if ((nums[i].first & nums[j].first) == 0) {
                    int i1 = nums[i].second, i2 = nums[j].second;
                    if (i1 < i2) return {i1, i2};
                    else return {i2, i1};
                }
            }
        }
        return {};
    }
};
