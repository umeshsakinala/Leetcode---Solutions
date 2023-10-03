class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        int result = 0;
        for(int num : nums)
        {
            if(count.find(num) != count.end())
            {
                result = result + count[num];
                count[num]++;
            }
            else
            {
                count[num] = 1;
            }
        }
        return result;
    }
};