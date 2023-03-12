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
private:
    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }

        int mid = (start + end) / 2;
        ListNode* one = merge(lists, start, mid);
        ListNode* two = merge(lists, mid + 1, end);
        ListNode* head;
        ListNode* cur;

        if (one && two) {
            if (one->val < two->val) {
                cur = one;
                head = one;
                one = one->next;
            } else {
                cur = two;
                head = two;
                two = two->next;
            }
        } else if (one) {
            cur = one;
            head = one;
            one = one->next;
        } else if (two) {
            cur = two;
            head = two;
            two = two->next;
        }

        while (one && two) {
            if (one->val < two->val) {
                cur->next = one;
                cur = cur->next;
                one = one->next;
            } else {
                cur->next = two;
                cur = cur->next;
                two = two->next;
            }
        }
        
        while (one) {
            cur->next = one;
            cur = cur->next;
            one = one->next;
        }

        while (two) {
            cur->next = two;
            cur = cur->next;
            two = two->next;
        }

        return head;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        return merge(lists, 0, lists.size() - 1);
    }
};
