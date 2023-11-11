class Graph {
public:
 vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }
    
    int shortestPath(int node1, int node2) {
        return f(node1, node2);
    }
    int f(int node, int end)
    {
        int n = adj.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, 1e9);
        dist[node] = 0;
        pq.push({0, node});
        while(!pq.empty())
        {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            for(auto it: adj[u])
            {
                int adjNode = it.first;
                int edW = it.second;
                if(w+edW<dist[adjNode])
                {
                    dist[adjNode] = w+edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist[end] != 1e9 ? dist[end] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */