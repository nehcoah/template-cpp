// 2806
// https://leetcode.cn/problems/account-balance-after-rounded-purchase/
// brute force

class Solution {
public:
    int accountBalanceAfterPurchase(int a) {
        int c = a % 10;
        if (c < 5) return 100 - (a - c);
        else return 100 - (a + 10 - c);
    }
};
