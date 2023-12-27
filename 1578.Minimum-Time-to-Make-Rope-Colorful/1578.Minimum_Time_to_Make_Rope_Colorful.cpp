class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int n = colors.length();
        int max_time = 0;
        int total_sum = 0;
        for(int i=0;i<n;i++){
            if(i>0 && colors.at(i) != colors.at(i-1)){
                minTime += total_sum - max_time;
                total_sum = max_time = 0;
            }
            total_sum += neededTime[i];
            max_time = std::max(max_time,neededTime[i]);
        }
        minTime += (total_sum - max_time);
        return minTime;
    }
};