class Solution {
public:
    int integerBreak(int n) {
        if(n < 4)
        {
            return n-1;
        }
        int remainder = n%3;
        if(remainder == 0)
        {
            return pow(3, n/3);
        }
        else if(remainder == 1)
        {
            return pow(3, (n/3)-1)*4;
        }
        else
        {
            return pow(3, n/3)*2;
        }
    }
};