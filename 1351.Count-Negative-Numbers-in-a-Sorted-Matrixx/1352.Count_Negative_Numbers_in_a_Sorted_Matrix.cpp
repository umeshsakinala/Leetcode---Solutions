class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size();
        int column = grid[0].size();
        int left = row-1;
        int right = 0;
        while(left >= 0 && right < column)
        {
            if(grid[left][right] < 0)
            {
                left--;
                count = count + column - right;
            }
            else
            {
                right++;
            }
        }
        return count;
    }
};
