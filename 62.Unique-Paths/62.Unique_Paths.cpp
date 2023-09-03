class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n == 1)
        {
            return 1;
        }
        int N = n + m - 2;
        int K = min(n - 1, m - 1);
        unsigned long long C=1LL;
        for(int i=1; i<=K; i++) 
        {
            C=C*(N-K+i)/i;
        }
        return C;
    }
};