class Solution {
public:
    int totalMoney(int n) {
        int count = 0;
        for(int i=1, k=0, j=1; i<=n; i++, k)
        {
            count = count + k + j;
            k++;
            if(i%7 == 0)
            {
                j++;
                k = 0;
            }
        }
        return count;
    }
};