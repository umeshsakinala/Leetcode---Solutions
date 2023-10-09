class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = -1;
        int b = -1;
        int pass = 0;
        int jump = 0;
        for(int i=0, j=nums.size()-1; i<nums.size(), j>=0; i++, j--)
        {
            if(pass == 0)
            {
                if(nums[i] == target)
                {
                    a = i;
                    pass = 1;
                }
            }
            if(jump == 0)
            {
                if(nums[j] == target)
                {
                    b = j;
                    jump = 1;
                }
            }
        }
        nums.clear();
        nums.push_back(a);
        nums.push_back(b);
        return nums;
    }
};