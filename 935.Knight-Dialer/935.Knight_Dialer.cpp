class Solution {
    
    int MOD = 1000000007;
    vector<vector<int>> nextPosition;
    vector<vector<int>> dp;

    int DFS(int position, int jumps)
    {
        if(jumps == 0)
            return 1;

        if(dp[position][jumps] != -1)
            return dp[position][jumps];

        int ret = 0;
        for(auto next : nextPosition[position])
            ret = (ret + DFS(next, jumps - 1)) % MOD;

        return dp[position][jumps] = ret;
    }

public:
    int knightDialer(int n) {
        
        nextPosition = { {5,7}, {6,8}, {3,7}, {2,8,10}, {}, {0,6,10}, {1,5}, {0,2}, {1,3}, {}, {3,5}, {} };
        dp = vector<vector<int>>(11, vector<int>(n + 1, -1));

        int ans = DFS(10, n - 1);
        for(int i = 0; i < 9; i++)
            ans = (ans + DFS(i, n - 1)) % MOD;

        return ans;
    }
};