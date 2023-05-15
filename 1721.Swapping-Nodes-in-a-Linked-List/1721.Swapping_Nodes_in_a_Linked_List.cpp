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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *x = head;
        ListNode *y = head;
        ListNode *z = head;
        while(k > 1)
        {
            x = x->next;
            z = z->next;
            k--;
        }
        while(z->next)
        {
            y = y->next;
            z = z->next;
        }
        int temp = y->val;
        y->val = x->val;
        x->val = temp;
        return head;
    }
};
