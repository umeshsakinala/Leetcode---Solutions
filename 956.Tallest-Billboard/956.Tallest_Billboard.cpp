class Solution {
public:
int height(int i, int j, vector<int>& rods, vector<vector<int>>& memoi, int& n)
{
    if(i >= n)
    {
        if(j == 5000)
        {
            return 0;
        }
        else
        {
            return INT_MIN;
        }
    }
    if(memoi[i][j] != INT_MIN)
    {
        return memoi[i][j];
    }
    int ans = height(i+1, j, rods, memoi, n);
    ans = max(ans, height(i+1, j-rods[i], rods, memoi, n));
    ans = max(ans, rods[i] + height(i+1, j+rods[i], rods, memoi, n));
    return memoi[i][j] = ans;
}
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> memoi(n, vector<int>(10001, INT_MIN));
        return height(0, 5000, rods, memoi, n);
    }
};