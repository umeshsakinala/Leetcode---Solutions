class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        if(n <= 2) return 0;
        int cur = 0;
        int ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    cur = j-i-1;
                }
                ans = max(ans, cur);
            }
        }
        return ans == 0 ? -1 : ans;
    }
};