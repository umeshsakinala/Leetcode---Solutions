class Solution {
public:
    int calc(int x)
    {
        return (x <= 1)? x : ((x <= 9)? 2 : ((x <= 99)? 3 : 4));
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        int T = s.size() - k;

        vector<vector<int>> dp(s.size() + 1, vector<int>(T + 1, 100000));
        dp[s.size()][T] = 0;

        for(int p = s.size()-1; p >= 0; --p)
        {
            for(int cnt = 0; cnt <= T; ++cnt)
            {
                for(int j = p, same = 0; j < s.size(); ++j)
                {
                    same += (s[j] == s[p]);
                    if(same + cnt > T) break;
                    dp[p][cnt] = min(dp[p][cnt], calc(same) + dp[j+1][cnt + same]);
                }
                dp[p][cnt] = min(dp[p][cnt], dp[p+1][cnt]);
            }
        }
        return dp[0][0];
    }
};