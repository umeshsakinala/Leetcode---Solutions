class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count=1;
        sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b)
        {
            return a[1]<b[1];
        });
        int arrow= points[0][1]; 
        for(auto &i: points)
        {
            if(arrow < i[0])
            {
                count++;
                arrow=i[1];
            }
        }
        return count;
    }
};
