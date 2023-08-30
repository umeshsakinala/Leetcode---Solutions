class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long a = 0;
        int last = nums.back();
        for(int i=nums.size()-2; i>=0; i--)
        {
            auto[quo, rem] = div(nums[i], last);
            if(quo == 0)
            {
                last = rem;
            }
            else if(rem == 0)
            {
                a = a + (quo-1);
            }
            else
            {
                a = a + quo;
                last = last - (last-rem+quo)/(quo+1);
            }
        }
        return a;
    }
};