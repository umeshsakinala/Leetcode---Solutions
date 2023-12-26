class Solution {
public:
    int mod=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> curr(target+1,0),prev(target+1,0);
        prev[0] = 1;
        for(int i=1; i<=n; i++)
        {
            for(int tar=1; tar<=target; tar++)
            {
                int maxFace=min(k,tar-i+1);
                long long total=0;
                for(int j=maxFace; j>=1; j--)
                {
                    total+=(prev[tar-j])%mod;
                }
                curr[tar]=total%mod;
            }
            prev=curr;
        }
        return prev[target];
    }
};