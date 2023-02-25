class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int high = 0;
        int temp;
        for(int i=0; i<prices.size(); i++)
        {
            temp = prices[i] - low;
            high = max(high, temp);
            low = min(low, prices[i]);
        }
        return high;
    }
};
