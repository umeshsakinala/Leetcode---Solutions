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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        ListNode *mid = findMiddle(head);
        TreeNode* root = new TreeNode(mid->val);
        if(head == mid)
        {
            return root;
        }
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = head;
        ListNode* a = nullptr;
        while(q && q->next)
        {
            a = p;
            p = p->next;
            q = q->next->next;
        }
        if(a)
        {
            a->next = nullptr;
        }
        return p;
    }
};
