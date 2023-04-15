class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> dp(k + 1, 0);
        for(auto& pile: piles)
        {
            for(size_t i = k; i >= 1; i--)
            {
                int csum = 0;
                for(int j = 0; j < min(i, pile.size()); j++)
                {
                    csum += pile[j];
                    dp[i] = max(dp[i], dp[i - j - 1] + csum);
                }
            }
        }
        return dp[k];
    }
};
