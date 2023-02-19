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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)    return ans; 
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        bool r = true;
        while(q.size()) {
            int size = q.size();
            v.clear();
            r = !r;
            for(int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front -> left != NULL)   q.push(front -> left);
                if(front -> right != NULL)   q.push(front -> right);
                v.push_back(front -> val);
            }
            if(r) reverse(v.begin(), v.end());
            ans.push_back(v);
        } 
        return ans;
    }
};
