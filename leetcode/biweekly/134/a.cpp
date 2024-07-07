class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0, n = colors.size();
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        for (int i = 1; i < n + 1; i++) {
            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) ans += 1;
        }
        return ans;
    }
};
