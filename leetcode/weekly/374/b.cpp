class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        ranges::sort(coins);
        int ans = 0;
        long long sum = 0;
        for (int i = 0; i < coins.size(); i++) {
            if (sum >= target) break;
            while (coins[i] > sum + 1) {
                ans++;
                sum += sum + 1;
            }
            sum += coins[i];
        }
        while (sum < target) {
            ans++;
            sum += sum + 1;
        }
        return ans;
    }
};
