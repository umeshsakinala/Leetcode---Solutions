class Solution {
public:
int mod=1e9+7;
int solve(int n, int m, int k,int maxvalue,vector<vector<vector<int>>>& dp)
{
    if(n==0 && k==0 )
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(k<0)
    {
        return 0;
    }
    if(dp[n][k][maxvalue] != -1) 
    {
        return dp[n][k][maxvalue];
    }
    int count=0;
    for(int i=1;i<=m;i++)
    {
        if(i>maxvalue)
        {
            count=(count%mod+solve(n-1,m,k-1,i,dp)%mod)%mod;
        }
        else
        {
            count=(count%mod+solve(n-1,m,k,maxvalue,dp)%mod)%mod;
        }
    }
    return dp[n][k][maxvalue]=count;
}
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(m+1,-1)));
        return solve(n,m,k,0,dp);
        
    }
};