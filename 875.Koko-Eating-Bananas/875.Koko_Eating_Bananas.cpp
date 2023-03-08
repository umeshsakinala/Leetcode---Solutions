class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int e = piles[piles.size()-1];
        int s = 1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            long long ans = 0;
            for(auto &i : piles)
            {
                ans = ans + ((i+mid-1)/mid);
            }
            if(ans > h)
            {
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return s;
    }
};
