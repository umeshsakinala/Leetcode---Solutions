class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(grid.size(), 0);
        vector<int> column(grid[0].size(), 0);
        int difference;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                row[i] += grid[i][j];
                column[j] += grid[i][j];
            }
        }
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                grid[i][j] = 2*(row[i] + column[j]) - m - n;
            }
        }
        return grid;
    }
};