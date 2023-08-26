class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int temp = INT_MIN;
        int ans = 0;
        for(const auto& i : pairs)
        {
            if(temp < i[0])
            {
                temp = i[1];
                ans++;
            }
        }
        return ans;
    }
};