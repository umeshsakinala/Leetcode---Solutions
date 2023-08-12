class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> previous(n,0);
        vector<int> current(n,0);
        previous[0] = 1;
        for(int i=0; i<m; i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                current[0] = 0;
            }
            else
            {
                current[0] = previous[0];
            }
            for(int j=1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    current[j] = 0;
                }
                else
                {
                    current[j] = current[j-1] + previous[j];
                }
            }
            previous = current;
        }
        return previous[n-1];
    }
};
