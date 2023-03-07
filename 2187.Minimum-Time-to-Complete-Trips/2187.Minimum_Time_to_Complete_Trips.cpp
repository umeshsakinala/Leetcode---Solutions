class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = 100000000000000;
        long long ans = r;
        while (l <= r)
        {
            long long m = (l+r)/2;
            long long trips = 0;
            for(int n : time)
            {
                trips += m / n;
            }
            if (trips >= totalTrips)
            {
                ans = m, r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        return ans;
    }
};
