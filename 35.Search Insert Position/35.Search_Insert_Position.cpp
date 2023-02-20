class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;
        while(first <= last)
        {
            int mid = (first+last)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                last = mid-1;
            }
            else
            {
                first = mid+1;
            }
        }
        return last+1;
    }
};
