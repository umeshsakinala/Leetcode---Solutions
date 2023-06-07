class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a || b || c)
        {
            if(c & 1)
            {
                if((a&1) == 0 && (b&1) == 0)
                {
                    flips++;
                }
            }
            else
            {
                if(a&1)
                {
                    flips++;
                }
                if(b&1)
                {
                    flips++;
                }
            }
            a = a/2;
            b = b/2;
            c = c/2;
        }
        return flips;
    }
};
