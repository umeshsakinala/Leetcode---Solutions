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
int distance = INT_MAX;
TreeNode* Prev;
void minDistance(TreeNode* root)
{
    if(root == NULL)
    {
        return ;
    }
    minDistance(root->left);
    if(Prev != NULL)
    {
        distance = min(distance, root->val - Prev->val);
    }
    Prev = root;
    minDistance(root->right);
}
    int getMinimumDifference(TreeNode* root) {
        minDistance(root);
        return distance;
    }
};