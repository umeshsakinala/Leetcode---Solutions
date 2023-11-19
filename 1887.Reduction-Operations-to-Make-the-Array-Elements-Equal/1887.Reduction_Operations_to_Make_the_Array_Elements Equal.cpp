class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> count;
        int operations = 0;
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }
        int prev = 0;
        for(auto i = count.rbegin(); i!=count.rend(); i++)
        {
            operations += prev;
            prev += i->second;
        }
        return operations;
    }
};