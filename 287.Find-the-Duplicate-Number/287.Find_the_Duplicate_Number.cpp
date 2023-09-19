class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a;
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<=nums.size())
        {
            if(nums[i] == nums[i+1])
            {
                a = nums[i];
                break;
            }
            i++;
        }
        return a;
    }
};