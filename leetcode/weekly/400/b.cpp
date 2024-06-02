class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = max(0, meetings[0][0] - 1), r = meetings[0][1];
        for (int i = 0; i < meetings.size(); i++) {
            if (meetings[i][0] <= r) r = max(r, meetings[i][1]);
            else ans += max(0, meetings[i][0] - r - 1), r = meetings[i][1];
        }
        return ans + max(0, days - r);
    }
};
