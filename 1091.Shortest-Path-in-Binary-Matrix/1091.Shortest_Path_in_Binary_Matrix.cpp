class Solution {
public:
    int dx[8]={0,1,-1,0,1,-1,-1,1};
    int dy[8]={1,0,0,-1,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty())
        {
            int cnt=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            if(x==n-1 and y==n-1)
            {
                return cnt;
            }
           
            for(int k=0;k<8;k++)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(newx<0 or newy<0 or newx>=n or newy>=n or vis[newx][newy]==1 or grid[newx][newy]==1)
                    continue;
                vis[newx][newy]=1;
                q.push({cnt+1,{newx,newy}});
            }
        }
        return -1;
    }
};
