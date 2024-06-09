class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        
        const int N = 1e5 + 1;
        bitset<N> f;
        f[0] = 1;
        for (int x : rewardValues) {
            f |= f << (N - x) >> (N - x) << x;
        }
        for (int x = *max_element(rewardValues.begin(), rewardValues.end()) * 2 - 1; x >= 0; x--) {
            if (f[x]) return x;
        }
        return 0;
    }
};
