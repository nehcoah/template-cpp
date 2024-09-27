class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int cur = min({num1 % 10, num2 % 10, num3 % 10}) * pow(10, i);
            ans += cur;
            num1 /= 10, num2 /= 10, num3 /= 10;
        }
        return ans;
    }
};
