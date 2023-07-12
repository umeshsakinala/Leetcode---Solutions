class Solution {
public:
bool graphVisited(vector<vector<int>>& graph, int src, vector<bool> &visited, vector<bool> &dfs)
{
    visited[src] = true;
    dfs[src] = true;
    for(int i=0; i<graph[src].size(); i++)
    {
        int child = graph[src][i];
        if(visited[child] == false)
        {
            if(graphVisited(graph, child, visited, dfs))
            {
                return true;
            }
        }
        else
        {
            if(dfs[child] == true)
            {
                return true;
            }
        }
    }
    dfs[src] = false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false), dfs(n, false);
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(graphVisited(graph, i, visited, dfs) == false)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};