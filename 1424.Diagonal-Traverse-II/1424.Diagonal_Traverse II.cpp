class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> diagonal;
        vector<vector<int>> temp{{0,0}};
        while(!temp.empty())
        {
            int row = temp[0][0];
            int col = temp[0][1];
            temp.erase(temp.begin());
            diagonal.push_back(nums[row][col]);
            if(col == 0 && row + 1 < nums.size())
            {
                temp.push_back({row + 1, col});
            }
            if(col + 1 < nums[row].size())
            {
                temp.push_back({row, col + 1});
            }
        }
        return diagonal;
    }
};