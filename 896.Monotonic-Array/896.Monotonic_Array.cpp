class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int pcount = 0;
        int ncount = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] - nums[i+1] > 0)
            {
                pcount++;
            }
            if(nums[i] - nums[i+1] < 0)
            {
                ncount++;
            }
            if(pcount > 0)
            {
                if(nums[i] - nums[i+1] < 0)
                {
                    return false;
                }
            }
            if(ncount > 0)
            {
                if(nums[i] - nums[i+1] > 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};