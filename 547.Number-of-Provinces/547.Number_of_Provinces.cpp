class Solution {
public:
void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i)
{
    visited[i] = true;
    for(int j=0; j<isConnected.size(); j++)
    {
        if(isConnected[i][j] == 1 && visited[j] == 0)
        {
            dfs(isConnected, visited, j);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int province = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                province++;
                dfs(isConnected, visited, i);
            }
        }
        return province;
    }
};
