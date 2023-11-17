class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maximum = INT_MIN;
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            maximum = max(maximum, nums[left] + nums[right]);
            left++;
            right--;
        }
        return maximum;
    }
};