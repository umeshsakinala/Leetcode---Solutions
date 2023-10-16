class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>  ans(rowIndex + 1, 1);
        for(int j = 1 ; j < rowIndex ; j++)
        {
            ans[j] = ans[j - 1] * (long)((rowIndex + 1) - j) / j;
        }
        return ans;
    }
};