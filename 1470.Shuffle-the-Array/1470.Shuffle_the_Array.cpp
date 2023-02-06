class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr;
        for(int i=0, j=n; i<n,j<2*n; i++,j++)
        {
            arr.push_back(nums[i]);
            arr.push_back(nums[j]);
        }
        return arr;
    }
};
