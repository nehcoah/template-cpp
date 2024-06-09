class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size(), cnt = 0, mx = skills[0], id = 0;
        for (int i = 1; i < n; i++) {
            if (skills[i] > mx) {
                cnt = 1; mx = skills[i]; id = i;
            } else {
                cnt += 1;
            }
            if (cnt == k) return id;
        }
        return id;
    }
};
