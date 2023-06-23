class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int count = 2;
        int n = nums.size();
        vector<vector<int>> memoi(n, vector<int>(2000, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int difference = nums[j] - nums[i] + 1000;
                memoi[j][difference] = max(2, memoi[i][difference] + 1);
                count = max(count, memoi[j][difference]);
            }
        }
        return count;
    }
};