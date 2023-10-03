class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [count = unordered_map<int, int> {}] (auto x, auto y) mutable {
return x + count[y]++;
        });
    }
};