class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                ans  = max(ans, a+b);
                b = a;
                a = 0;
            }
            else
            {
                a++;
            }
        }
        if(a == nums.size())
        {
            return nums.size()-1;
        }
        return max(ans, a+b);
    }
};