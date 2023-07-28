class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans(n, vector<int>(n,0));
        for(int i=0; i<n; i++)
        {
            ans[i][i] = nums[i];
        }
        for(int i=2; i<=n; i++)
        {
            for(int j=0; j<=n-i; j++)
            {
                int k = j+i-1;
                ans[j][k] = max(nums[j] - ans[j+1][k], nums[k] - ans[j][k-1]);
            }
        }
        return ans[0][n-1] >= 0;
    }
};