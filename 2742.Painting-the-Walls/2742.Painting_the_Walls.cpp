class Solution {
public:
    int solve(int idx, int remaining, vector<int>& cost, vector<int>& time, vector<vector<int>>& dp) {
        int n = cost.size(); 
        
        if (remaining <= 0)
            return 0;
        
        if (idx == n) {
            return 1e9;
        }
        
        if (dp[idx][remaining] != -1) {
            return dp[idx][remaining];
        }
        
        int paint = cost[idx] + solve(idx + 1, remaining - 1 - time[idx], cost, time, dp);
        int not_paint = solve(idx + 1, remaining, cost, time, dp);
        
        return dp[idx][remaining] = min(paint, not_paint);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size() + 1, vector<int>(cost.size() + 1, -1));
        return solve(0, cost.size(), cost, time, dp);
    }
};