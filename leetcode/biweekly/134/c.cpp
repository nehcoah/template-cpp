class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), ans = 0;
        for (int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int cnt = 0;
        for (int i = 1; i < k; i++) {
            if (colors[i] == colors[i - 1]) {
                cnt += 1;
            }
        }
        ans += cnt == 0;
        for (int i = k; i < colors.size(); i++) {
            cnt += colors[i] == colors[i - 1];
            cnt -= colors[i - k] == colors[i - k + 1];
            ans += cnt == 0;
        }
        return ans;
    }
};
