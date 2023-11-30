class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
        {
            return 0;
        }
        int temp = 1;
        while(temp * 2 <= n)
        {
            temp <<= 1;
        }
        return minimumOneBitOperations(n ^ (temp | temp >> 1)) + 1 + temp - 1;
    }
};