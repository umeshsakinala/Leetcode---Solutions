class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int Min = -1;
        int Max = -1;
        int bound = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] >= minK && nums[i] <= maxK)
            {
                Min = (nums[i] == minK) ? i : Min;
                Max = (nums[i] == maxK) ? i : Max;
                ans = ans + max(0, min(Min, Max)-bound);
            }
            else
            {
                bound = i;
                Min = -1;
                Max = -1;
            }
        }
        return ans;
    }
};
