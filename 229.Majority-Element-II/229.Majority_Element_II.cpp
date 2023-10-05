class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
        }
        vector<int> nums1;
        for(auto i: arr)
        {
            if(i.second > nums.size()/3)
            {
                nums1.push_back(i.first);
            }
        }
        return nums1;
    }
};