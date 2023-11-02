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
    vector<int> solve(TreeNode* root){
        vector<int> v(3,0);
        if(!root)
        return v;
        if(!root->left&&!root->right)
        {
            v[0]=1;
            v[1]=root->val;
            v[2]=1;
        }
        vector<int> l=solve(root->left);
        vector<int> r=solve(root->right);
        v[0]=l[0]+r[0]+1;
        v[1]=l[1]+root->val+r[1];
        v[2]=l[2]+r[2];
        if(v[1]/v[0]==root->val)
        v[2]++;
        return v;
    }
    int averageOfSubtree(TreeNode* root) {
        vector<int> v=solve(root);
        return v[2];
    }
};