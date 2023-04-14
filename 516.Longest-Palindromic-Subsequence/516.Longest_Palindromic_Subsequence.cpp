class Solution {
public:
    int longestPalindromeSubseq(string s){
        int m = s.size();
        int tab[3][m];
        for(int i = 0; i<m; i++)
        {
            tab[0][i] = 0;
            tab[1][i] = 1;
        }
        int _2, _1, _0;
        for(int gap = 1; gap<m; gap++)
        {
            _2 = (gap+1)%3, _1 = (gap+3)%3, _0 = (gap-1)%3;
            for(int i = 0,j = gap; j<m; i++,j++ )
            {
                if(s[i] == s[j])
                {
                    tab[_2][j] = tab[_0][j-1]+2;
                }
                else
                {
                    tab[_2][j] = max(tab[_1][j],tab[_1][j-1]);
                }
            }   
        }
        return tab[m%3][m-1];
    }
};
