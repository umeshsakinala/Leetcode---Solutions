class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> eliminate;
        int n = dist.size();
        for(int i=0; i<n; i++)
        {
            eliminate.push_back((float)dist[i]/(float)speed[i]);
        }
        sort(eliminate.begin(), eliminate.end());
        int i;
        for(i=0; i<n; i++)
        {
            if(i >= eliminate[i])
            {
                return i;
            }
        }
        return eliminate.size();
    }
};