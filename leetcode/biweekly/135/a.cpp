class Solution {
public:
    string losingPlayer(int x, int y) {
        int cnt = min(x, y / 4);
        return cnt % 2 ? "Alice" : "Bob";
    }
};
