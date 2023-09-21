// https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int p1 = 1, p2 = 1;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++){
            p1 = p2 = 1;
            for (int j = i - 1; j >= 0 && j >= i - 2; j--) if (player1[j] == 10) p1 = 2;
            for (int j = i - 1; j >= 0 && j >= i - 2; j--) if (player2[j] == 10) p2 = 2;
            s1 += p1 * player1[i];
            s2 += p2 * player2[i];
        }
        return s1 == s2 ? 0 : s1 > s2 ? 1 : 2;
    }
};
