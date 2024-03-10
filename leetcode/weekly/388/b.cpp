class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), greater<>());
        for (int i = 0; i < happiness.size() && k--; i++) {
            ans += max(happiness[i] - i, 0);
        }
        return ans;
    }
};
