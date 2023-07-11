/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> graph[500];
void TreetoGraph(TreeNode* root)
{
    if(!root)
    {
        return ;
    }
    if(root->left)
    {
        graph[root->val].push_back(root->left->val);
        graph[root->left->val].push_back(root->val);
    }
    if(root->right)
    {
        graph[root->val].push_back(root->right->val);
        graph[root->right->val].push_back(root->val);
    }
    TreetoGraph(root->left);
    TreetoGraph(root->right);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreetoGraph(root);
        queue<int> q;
        q.push(target->val);
        int visited[500] = {0};
        vector<int> ans;
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            level++;
            for(int i=0; i<n; i++)
            {
                int node = q.front();
                q.pop();
                if(level == k+1)
                {
                    ans.push_back(node);
                }
                visited[node] = 1;
                for(int x: graph[node])
                {
                    if(!visited[x])
                    {
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};