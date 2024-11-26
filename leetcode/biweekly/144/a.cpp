class Solution {
public:
    bool canAliceWin(int n) {
        int cnt = 0, cur = 10;
        while (true) {
            cnt += 1;
            if (n < cur) break;
            n -= cur--;
        }
        return cnt % 2 == 0;
    }
};
