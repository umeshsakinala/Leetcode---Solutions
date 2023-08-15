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
    ListNode* partition(ListNode* head, int x) {
        ListNode p(0), q(0);
        ListNode* p_current = &p;
        ListNode* q_current = &q;
        while(head)        
        {
            if(head->val < x)
            {
                p_current->next = head;
                p_current = head;
            }
            else
            {
                q_current->next = head;
                q_current = head;
            }
            head = head->next;
        }
        q_current->next = nullptr;
        p_current->next = q.next;
        return p.next;
    }
};
