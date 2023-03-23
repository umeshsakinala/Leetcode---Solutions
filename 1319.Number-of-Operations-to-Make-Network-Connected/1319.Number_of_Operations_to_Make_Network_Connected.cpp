class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<bool>&visited, int currNode)
    { 
        visited[currNode] = true;
        for (int adjNode : adj[currNode])
        {
            if (visited[adjNode]) continue;
            dfs(adj, visited, adjNode);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int currWireCount = connections.size();
        int extraWires = currWireCount - (n - 1);
        if (extraWires < 0) return -1;
        vector<vector<int>>adj(n);
        for (vector<int>connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        vector<bool>visited(n, false);
        int componentCount = 0;
        for (int node = 0; node < n; node++)
        {
            if (visited[node]) continue;
            dfs(adj, visited, node);
            componentCount++;
        }
        return componentCount - 1;
    }
};
