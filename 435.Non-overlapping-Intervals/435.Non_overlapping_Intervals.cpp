class Solution {
public:
static bool compare(vector<int>&v1, vector<int>&v2)
{
    return v1[1] < v2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int pre = 0;
        int res = 0;
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[pre][1] > intervals[i][0])
            {
                res++;
            }
            else
            {
                pre = i;
            }
        }
        return res;
    }
};