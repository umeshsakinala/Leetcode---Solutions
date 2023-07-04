class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int ans;
        if(nums.size() == 1)
        {
            ans = nums[0];
        }
        for(int i = 1; i<nums.size(); i++)
        {   
            if(nums[i-1] == nums[i])
            {
                count++;
            }
            else
            {
                if(i == nums.size()-1)
                {
                    ans = nums[i];
                    break;
                }
                if(count == 1)
                {
                    ans = nums[i-1];
                    break;
                }
                count = 1;
            }  
        }
        return ans;
    }
};
