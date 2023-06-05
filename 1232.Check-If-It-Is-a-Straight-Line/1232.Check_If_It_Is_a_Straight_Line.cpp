class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int num = coordinates[1][1] - coordinates[0][1];
        int denum = coordinates[1][0] - coordinates[0][0];
        for(int i=0; i<coordinates.size(); i++)
        {
            if(num*(coordinates[i][0] - coordinates[1][0]) != denum*(coordinates[i][1] - coordinates[1][1]))
            {
                return false;
            }
        }
        return true;
    }
};
