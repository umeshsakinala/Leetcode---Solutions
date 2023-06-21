class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long minimum = 0;
        long long maximum = 1e6+2;
        long long mid, a, b, ans = LONG_LONG_MAX;
        int n = nums.size();
        while(minimum <= maximum)
        {
            mid = (maximum + minimum)/2;
            a = 0;
            b = 0;
            for(int i=0; i<n; i++)
            {
                a = a + abs(mid - nums[i]) * 1LL*cost[i];
                b = b + abs(mid + 1 - nums[i]) * 1LL*cost[i];
            }
            ans = min({a, b, ans});
            if(b > a)
            {
                maximum = mid - 1;
            }
            else
            {
                minimum = mid + 1;
            }
        }
        return ans;
    }
};