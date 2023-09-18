// https://leetcode.cn/problems/relocate-marbles/

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> s;
        for (int x : nums) s.insert(x);
        for (int i = 0; i < moveFrom.size(); i++) {
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
        vector<int> ans;
        for (int x : s) ans.push_back(x);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
