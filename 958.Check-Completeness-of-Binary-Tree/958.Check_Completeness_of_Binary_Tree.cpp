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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        int full = 0;
        while(!q.empty())
        {
            auto Node = q.front();
            q.pop();
            if(full && Node != NULL)
            {
                return false;
            }
            if(Node == NULL)
            {
                full = 1;
                continue;
            }
            q.push(Node->left);
            q.push(Node->right);
        }
        return true;
    }
};
