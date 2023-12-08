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
void preorder(TreeNode* root, string &treestr) {
    if(!root)
    {
        return ;
    }
    treestr = treestr + to_string(root->val);
    if(root->left || root->right)
    {
        treestr = treestr + '(';
        preorder(root->left, treestr);
        treestr = treestr + ')';
    }
    if(root->right)
    {
        treestr = treestr + '(';
        preorder(root->right, treestr);
        treestr = treestr + ')';
    }
}
    string tree2str(TreeNode* root) {
        string treestr = "";
        int flag = -1;
        preorder(root, treestr);
        return treestr;
    }
};