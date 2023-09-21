class Solution {
public:
    void Merge(vector<int>& nums1, vector<int>& nums2, vector<int>& nums, int m, int n)
    {
        int i, j, k;
        i = j = k = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        for(; i < nums1.size(); i++)
        {
            nums.push_back(nums1[i]);
        }
        for(; j < nums2.size(); j++)
        {
            nums.push_back(nums2[j]);
        }
    }
        
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        float median;
        vector<int> nums;
        int m = nums1.size();
        int n = nums2.size();
        Merge(nums1, nums2, nums, m, n);
        if(nums.size()%2 != 0)
        {
            median = (float) nums[(nums.size()/2)];
        }
        else
        {
            median = (float) (nums[nums.size()/2] + nums[(nums.size()/2)-1])/2;
        }
        return median;
    }
};