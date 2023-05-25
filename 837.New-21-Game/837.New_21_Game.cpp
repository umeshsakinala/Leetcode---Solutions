class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k-1+maxPts)
        {
            return 1.0;
        }
        double ans = 0.0;
        vector<double> arr(n+1);
        arr[0] = 1.0;
        double sum = arr[0];
        for(int i=1; i<=n; i++)
        {
            arr[i] = sum/maxPts;
            if(i < k)
            {
                sum = sum + arr[i];
            }
            else
            {
                ans = ans + arr[i];
            }
            if(i - maxPts >= 0)
            {
                sum = sum - arr[i-maxPts];
            }
        }
        return ans;
    }
};
