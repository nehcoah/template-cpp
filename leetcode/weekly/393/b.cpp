unordered_set<int> st;

auto init = []() {
    for (int i = 2; i < 101; i++) {
        bool ok = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) ok = false;
        }
        if (ok) st.insert(i);
    }
    return 0;
}();

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int ans = 0, pre = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i])) {
                if (pre == -1) pre = i;
                ans = max(ans, i - pre);
            }
        }
        return ans;
    }
};
