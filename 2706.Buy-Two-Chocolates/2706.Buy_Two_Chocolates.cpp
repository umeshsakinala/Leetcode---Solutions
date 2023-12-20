class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini = INT_MAX;
        int mini_two = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i] < mini)
            {
                mini_two = mini;
                mini = prices[i];
            }
            else
            {
                mini_two = min(mini_two, prices[i]);
            }
        }
        int amount = mini + mini_two;
        int remaining = money - amount;
        if(money < amount)
        {
            return money;
        }
        else
        {
            return remaining;
        }
    }
};