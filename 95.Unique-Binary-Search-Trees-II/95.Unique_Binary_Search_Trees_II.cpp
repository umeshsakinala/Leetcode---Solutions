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
vector<TreeNode*> constructTrees(int start, int end)
{
    if(start > end)
    {
        return {NULL};
    }
    if(start == end)
    {
        return {new TreeNode(start)};
    }
    vector<TreeNode*> answer;
    for(int i=start; i<=end; i++)
    {
        vector<TreeNode*> leftsubtree = constructTrees(start, i-1);
        vector<TreeNode*> rightsubtree = constructTrees(i+1, end);
        for(TreeNode* l : leftsubtree)
        {
            for(TreeNode* r : rightsubtree)
            {
                TreeNode* root = new TreeNode(i);
                root->left = l;
                root->right = r;
                answer.push_back(root);
            }
        }
    }
    return answer;
}
    vector<TreeNode*> generateTrees(int n) {
        return constructTrees(1, n);
    }
};