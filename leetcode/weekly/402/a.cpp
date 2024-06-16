class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        vector<int> cnt(24);
        int ans = 0;
        for (int x : hours) {
            x %= 24;
            ans += cnt[x == 0 ? 0 : 24 - x];
            cnt[x] += 1;
        }
        return ans;
    }
};
