class Solution {
public:
    int maxBottlesDrunk(int a, int b) {
        int ans = 0, e = 0;
        while (a) {
            ans += 1, e += 1, a -= 1;
            if (e == b) e = 0, b += 1, a += 1;
        }
        return ans;
    }
};
