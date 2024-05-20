class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int c = 0; c < 10; c++) {
            vector<int> cnt(10);
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) continue;
                cnt[nums[i] % 10] += 1;
                nums[i] /= 10;
            }
            long long sum = 0;
            for (int x : cnt) {
                ans += sum * x;
                sum += x;
            }
        }
        return ans;
    }
};
