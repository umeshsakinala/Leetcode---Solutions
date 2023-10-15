class Solution {
public:
    int mod = 1e9+7 ;
    int solve(int steps,int &n,int i,vector<vector<int>> &dp)
    {
        if(steps == 0  && i == 0)
           return 1 ;
        if(i < 0 || i >= n || steps <= 0 || i > steps)
           return 0 ;
        
        if(dp[i][steps] != -1)
           return dp[i][steps] ;

        return dp[i][steps] = ((solve(steps-1,n,i-1,dp) % mod + solve(steps-1,n,i,dp) % mod) % mod + solve(steps-1,n,i+1,dp)%mod)%mod  ;
    }
    int numWays(int steps, int arrLen) 
    {
         vector<vector<int>> dp(steps+1,vector<int> (steps+1,-1)) ;
         return solve(steps,arrLen,0,dp)%mod ;
    }
};