class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int day,int travelTillIndex,vector<int>& dp)
    {
        int s=days.size();
        while(day<s && days[day]<=travelTillIndex)
        {
            day++;
        }
        if(dp[day]!=-1)
        {
            return dp[day];
        }
        if(day<s)
        {
            int one=solve(days,costs,day+1,days[day],dp)+costs[0];
            int seven=solve(days,costs,day+1,days[day]+6,dp)+costs[1];
            int thirty=solve(days,costs,day+1,days[day]+29,dp)+costs[2];   
            return dp[day]=min(one,min(seven,thirty));
        }
        return 0;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int s=days.size();
        vector<int> dp(days[s-1],-1);  
        return solve(days,costs,0,0,dp);
    }
};
