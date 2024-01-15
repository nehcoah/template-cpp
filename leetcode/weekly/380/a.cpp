class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> cnt(101);
        for (int x : nums) {
            cnt[x]++;
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        int ans = 0;
        for (int x : cnt) {
            if (x == mx) ans += x;
        }
        return ans;
    }
};
