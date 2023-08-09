class Solution {
public:
bool solve(vector<int>& nums, int p, int mid)
{
    int count = 0;
    int max = 0;
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] - nums[i-1] <= mid)
        {
            i++;
            count++;
        }
    }
    return count >= p;
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back();
        int ans = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(solve(nums, p, mid))
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
};