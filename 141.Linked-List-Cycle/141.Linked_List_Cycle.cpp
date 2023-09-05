/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
			if(head == NULL) return false;
        ListNode *p = head;
        ListNode *q = head;
        while(true)
				{
					p = p->next;
					q = q->next;
					if(NULL != q) q = q->next;
					if(NULL == q || NULL == p) return false;
					else if(p == q) return true;
				}
    }
};