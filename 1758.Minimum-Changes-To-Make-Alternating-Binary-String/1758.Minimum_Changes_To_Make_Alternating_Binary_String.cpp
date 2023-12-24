class Solution {
public:
    int minOperations(string s) {
        int odd = 0;
        int even = 0;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(i & 1)
            {
                if(s[i] == '0')
                {
                    odd++;
                }
                else
                {
                    even++;
                }
            }
            else
            {
                if(s[i] == '1')
                {
                    odd++;
                }
                else
                {
                    even++;
                }
            }
        }
        return min(odd, even);
    }
};