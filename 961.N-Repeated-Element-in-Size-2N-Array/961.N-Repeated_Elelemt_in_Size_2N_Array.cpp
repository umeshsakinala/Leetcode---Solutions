class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int temp;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == nums[i+1])
            {
                temp = nums[i];
                break;
            }
        }
        return temp;
    }
};
