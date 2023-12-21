class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int max_diff=0;
        for(int i=0;i<points.size()-1;i++)
        {
            max_diff = max(points[i+1][0]-points[i][0],max_diff);
        }
        return max_diff;
    }
};