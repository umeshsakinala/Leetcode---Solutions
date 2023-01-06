class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int a = 0;
        sort(costs.begin(), costs.end());
        for(int i=0; i<costs.size(); i++)
        {
            if(costs[a] <= coins && a<costs.size())
            {
                coins = coins - costs[a];
                a++;
            }
        }
        return a;
    }
};

