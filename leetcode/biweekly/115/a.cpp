class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ans;
        vector<int> nums;
        int cnt = 0;
        for (auto s : words) {
            if (s == "prev") {
                cnt++;
                if (cnt <= nums.size()) ans.push_back(nums[nums.size() - cnt]);
                else ans.push_back(-1);
            } else {
                nums.push_back(stoi(s));
                cnt = 0;
            }
        }
        return ans;
    }
};
