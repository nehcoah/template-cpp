class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0, cur = 0;
        for (int x : batteryPercentages) {
            if (x - cur > 0) {
                ans++;
                cur++;
            }
        }
        return ans;
    }
};
