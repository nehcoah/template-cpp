/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        auto dummy = new ListNode(-1, head);
        unordered_set<int> st{nums.begin(), nums.end()};
        auto p = dummy;
        while (p->next) {
            if (st.count(p->next->val)) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};
