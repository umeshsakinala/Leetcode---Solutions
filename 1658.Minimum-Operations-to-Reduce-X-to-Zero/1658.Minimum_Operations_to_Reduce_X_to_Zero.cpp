class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        int maxlen = -1;
        int currsum = 0;
        for(int l=0, r=0; r<nums.size(); r++)
        {
            currsum = currsum + nums[r];
            while(l <= r && currsum > totalsum - x)
            {
                currsum = currsum - nums[l++];
            }
            if(currsum == totalsum - x)
            {
                maxlen = max(maxlen, r-l+1);
            }
        }
        return maxlen == -1 ? -1 : nums.size() - maxlen;
    }
};