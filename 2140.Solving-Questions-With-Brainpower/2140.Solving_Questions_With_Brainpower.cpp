class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        dp[questions.size()-1] = questions[questions.size()-1][0];
        for(int i=questions.size()-2; i>=0; i--)
        {
            int flag = i+questions[i][1] + 1;
            dp[i] = dp[i+1];
            if(flag < questions.size() && dp[i] < dp[flag] + questions[i][0])
            {
                dp[i] = questions[i][0] + dp[flag];
            }
            else if(dp[i] < questions[i][0])
            {
                dp[i] = questions[i][0];
            }
        }
        return dp[0];
    }
};
