// https://leetcode.cn/problems/number-of-adjacent-elements-with-the-same-color/

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0), ans;
        int cur = 0;
        for (auto& q : queries){
            int i = q[0], c = q[1];
            if (nums[i] != 0 && (i > 0 && nums[i] == nums[i - 1])) cur--;
            if (nums[i] != 0 && (i < n - 1 && nums[i] == nums[i + 1])) cur--;
            nums[i] = c;
            if (i > 0 && nums[i] == nums[i - 1]) cur++;
            if (i < n - 1 && nums[i] == nums[i + 1]) cur++;
            ans.push_back(cur);
        }
        return ans;
    }
};
