class Solution {
public:
    void dfs(vector<int> adj[], int u, vector<bool>& vis, long long &count)
    {
        count++;       
        vis[u] = true;        
        for(auto v : adj[u])
        {
            if(vis[v] == false)
            {
                dfs(adj, v, vis, count);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {       
        vector<int> adj[n];       
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];          
            int v = edges[i][1];           
            adj[u].push_back(v);            
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);        
        long long ans = 0;      
        long long curr_sum = 0;        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == false)
            {
                long long count = 0;  
                dfs(adj, i, vis, count);               
                ans += curr_sum * count;               
                curr_sum += count;
            }
        }       
        return ans;
    }
};
