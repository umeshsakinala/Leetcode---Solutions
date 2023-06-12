class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string temp = "";
        for(int i=0; i<nums.size(); i++)
        {
            int j = i;
            while(j+1 < nums.size() && nums[j+1] == nums[j] + 1)
            {
                j++;
            }
            if(j > i)
            {
                temp = temp + to_string(nums[i]);
                temp = temp + "->";
                temp = temp + to_string(nums[j]);
            }
            else
            {
                temp = temp + to_string(nums[i]);
            }
            res.push_back(temp);
            temp = "";
            i = j;
        }
        return res;
    }
};
