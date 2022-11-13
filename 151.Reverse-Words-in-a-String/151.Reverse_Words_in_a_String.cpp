class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0;
        int end = 0;
        int it = 0;
        while(it < s.size())
        {
            while(it < s.size() && s[it]!=' ')
            {
                s[end] = s[it];
                end++;
                it++;
            }
            if(start < end)
            {
                reverse(s.begin() + start, s.begin() + end);
                if(end == s.size())
                {
                    break;
                }
                s[end] = ' ';
                end++;
                start = end;
            }
            it++;
        }
        if(end > 0 && s[end-1] == ' ')
        {
            s.resize(end-1);
        }
        else
        {
            s.resize(end);
        }
        return s;
    }
};
