class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        
        vector<int> f(*max_element(rewardValues.begin(), rewardValues.end()) * 2 + 1);
        f[0] = 1;
        for (int x : rewardValues) {
            for (int y = x - 1; y >= 0; y--) {
                f[y + x] |= f[y];
            }
        }
        for (int x = f.size() - 1; x >= 0; x--) {
            if (f[x]) return x;
        }
        return 0;
    }
};
