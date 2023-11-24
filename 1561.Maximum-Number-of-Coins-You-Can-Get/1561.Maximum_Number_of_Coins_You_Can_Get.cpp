class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int left = 0;
        int right = piles.size() - 1;
        int coins = 0;
        sort(piles.begin(), piles.end());
        while(left < right)
        {
            coins = coins + piles[right-1];
            right = right - 2;
            left++;
        }
        return coins;
    }
};