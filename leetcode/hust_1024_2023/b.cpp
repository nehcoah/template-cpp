class Solution {
public:
    int specialChopsticks(vector<int>& chopsticks) {
        int n = chopsticks.size();
        for (int x = 1; x <= n; x++) {
            int cnt = 0;
            for (int c : chopsticks) if (c >= x) cnt++;
            if (cnt == x) return x;
        }
        return -1;
    }
};
