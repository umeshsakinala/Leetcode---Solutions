class Solution {
public:
bool maximum(vector<int>& candies, int a)
{
    for(int i = 0; i<candies.size(); i++)
    {
        if(a < candies[i])
        {
            return false;
        }
    }
    return true;
}
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> extra;
        for(int i=0; i<candies.size(); i++)
        {
            extra.push_back(maximum(candies, candies[i]+extraCandies));
        }
        return extra;
    }
};
