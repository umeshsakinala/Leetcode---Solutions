class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int x = 0;
        int a = 0;
        int result = 0;
        int minimum = nums.size()+1;
        while(x < nums.size())
        {
            result = result + nums[x];
            while(a <= x && result >= target)
            {
                minimum = min(minimum, x-a+1);
                result = result - nums[a];
                a++;
            }
            x++;
        }
        if(minimum == nums.size()+1)
        {
            return 0;
        }
        else
        {
            return minimum;
        }
    }
};