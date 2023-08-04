class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> ans(n, 0);
        for(int i=-1; i<n; i++)
        {
            if(i >= 0 && ans[i] == false)
            {
                continue;
            }
            for(auto word: wordDict)
            {
                int j=0;
                while(j < word.size() && i+1+j < n && word[j] == s[i+1+j])
                {
                    j++;
                }
                if(j == word.size())
                {
                    ans[i+word.size()] = true;
                }
            }
        }
        return ans[n-1];
    }
};