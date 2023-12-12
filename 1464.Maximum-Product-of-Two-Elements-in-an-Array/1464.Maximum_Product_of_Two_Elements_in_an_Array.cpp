class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[nums.size()-1] - 1;
        nums.pop_back();
        int b = nums[nums.size()-1] - 1;
        return a*b;
    }
};