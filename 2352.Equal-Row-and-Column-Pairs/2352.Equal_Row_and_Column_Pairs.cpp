class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        vector<vector<int>> ans;
        for(int i=0; i<n;i++)
        {
            vector<int> temp;
            for(int j = 0; j < n; j++)
            {
                temp.push_back(grid[j][i]);
            }
            ans.push_back(temp);
            cout<<endl;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i] == ans[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};
