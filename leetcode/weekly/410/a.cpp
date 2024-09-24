class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0;
        for (auto &s : commands) {
            if (s == "UP") x -= n;
            else if (s == "RIGHT") x += 1;
            else if (s == "DOWN") x += n;
            else x -= 1;
        }
        return x;
    }
};
