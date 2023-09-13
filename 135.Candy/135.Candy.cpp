class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candycount(ratings.size(), 1);
        for(int i=1; i<ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                candycount[i] = candycount[i-1] + 1;
            }
        }
        for(int i=ratings.size()-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                candycount[i] = max(candycount[i], candycount[i+1] + 1);
            }
        }
        int count = 0;
        for(int candy : candycount)
        {
            count = count + candy;
        }
        return count;
    }
};