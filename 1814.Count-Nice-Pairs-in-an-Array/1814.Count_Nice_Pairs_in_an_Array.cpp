class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> op_nums;
        int ans = 0;
        for (int n : nums)
        {
            string s = to_string(n);
            reverse(s.begin(), s.end());
            int r = stoi(s);
            ans += op_nums[n-r]++;
            ans %= (int)(1e9 + 7);
        }
        return ans;
    }
};