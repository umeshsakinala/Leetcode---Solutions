class Solution {
public:
int signFunc(int neg_count, int zero, int pos_count, vector<int>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        if(nums[i] < 0)
        {
            neg_count++;
        }
        else if(nums[i] == 0)
        {
            zero++;
        }
        else
        {
            pos_count++;
        }
    }
    if(zero > 0)
    {
        return 0;
    }
    else if(neg_count%2 == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
    int arraySign(vector<int>& nums) {
        int neg_count = 0;
        int zero = 0;
        int pos_count = 0;
        return signFunc(neg_count, zero, pos_count, nums);
    }
};
