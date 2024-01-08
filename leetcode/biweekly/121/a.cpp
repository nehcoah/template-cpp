class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st{nums.begin(), nums.end()};
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) ans += nums[i];
            else break;
        }
        while (true) {
            if (st.count(ans)) ans++;
            else break;
        }
        return ans;
    }
};
